//BusinessCardBinder.c
#include "BusinessCardBinder.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//�����Լ�����
int main(int argc, char *argv[]) {
	BusinessCardBinder businessCardBinder;
	BusinessCard businessCard;
	BusinessCard *index;
	BusinessCard* (*indexes);
	ULong count;
	ULong i;

	//Create
	BusinessCardBinder_Create(&businessCardBinder);

	//TakeIn
	strcpy(businessCard.personal.name, "ȫ�浿");
	strcpy(businessCard.personal.position, "���");
	strcpy(businessCard.personal.cellularPhoneNumber, "0105879424");
	strcpy(businessCard.personal.emailAddress, "hong@");
	strcpy(businessCard.company.name, "�Ｚ");
	strcpy(businessCard.company.telephoneNumber, "025879424");
	strcpy(businessCard.company.url, "SAMSUNG.com");
	strcpy(businessCard.company.address, "����� ���ʱ�");
	strcpy(businessCard.company.faxNumber, "025879424");
	index = TakeIn(&businessCardBinder, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);
	//TakeIn
	strcpy(businessCard.personal.name, "�̱浿");
	strcpy(businessCard.personal.position, "�븮");
	strcpy(businessCard.personal.cellularPhoneNumber, "0105879424");
	strcpy(businessCard.personal.emailAddress, "lee@");
	strcpy(businessCard.company.name, "����");
	strcpy(businessCard.company.telephoneNumber, "025879424");
	strcpy(businessCard.company.url, "HUNDAI.com");
	strcpy(businessCard.company.address, "����� �߱�");
	strcpy(businessCard.company.faxNumber, "025879424");
	index = TakeIn(&businessCardBinder, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);
	//TakeIn
	strcpy(businessCard.personal.name, "ȫ�浿");
	strcpy(businessCard.personal.position, "����");
	strcpy(businessCard.personal.cellularPhoneNumber, "0105879424");
	strcpy(businessCard.personal.emailAddress, "hong2@");
	strcpy(businessCard.company.name, "����");
	strcpy(businessCard.company.telephoneNumber, "025879424");
	strcpy(businessCard.company.url, "LG.com");
	strcpy(businessCard.company.address, "����� ���ʱ�");
	strcpy(businessCard.company.faxNumber, "025879424");
	index = TakeIn(&businessCardBinder, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Find
	Find(&businessCardBinder, "ȫ�浿", &indexes, &count);
	i = 0;
	while (i < count) {
		printf("%s %s %s %s %s %s %s %s %s\n", indexes[i]->personal.name, indexes[i]->personal.position,
			indexes[i]->personal.cellularPhoneNumber, indexes[i]->personal.emailAddress,
			indexes[i]->company.name, indexes[i]->company.telephoneNumber, indexes[i]->company.url,
			indexes[i]->company.address, indexes[i]->company.faxNumber);
		i++;
	}
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//FindByCompanyNames
	index = FindByCompanyName(&businessCardBinder, "�Ｚ");
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Previous
	index = BusinessCardBinder_Previous(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//First & Previous, UnderFlow Check
	index = BusinessCardBinder_First(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	index = BusinessCardBinder_Previous(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Next
	index = BusinessCardBinder_Next(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Last & Next, Overflow check
	index = BusinessCardBinder_Last(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	index = BusinessCardBinder_Next(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//TakeOut
	//index = BusinessCardBinder_Last(&businessCardBinder);
	businessCard = TakeOut(&businessCardBinder, index);
	printf("%s %s %s %s %s %s %s %s %s\n", businessCard.personal.name, businessCard.personal.position,
		businessCard.personal.cellularPhoneNumber, businessCard.personal.emailAddress,
		businessCard.company.name, businessCard.company.telephoneNumber, businessCard.company.url,
		businessCard.company.address, businessCard.company.faxNumber);

	//Destroy
	BusinessCardBinder_Destroy(&businessCardBinder);

	return 0;
}

/*
�Լ���Ī : BusinessCardBinder_Create
��    �� : ���԰���ö�� �ʱ�ȭ �Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
void BusinessCardBinder_Create(BusinessCardBinder *businessCardBinder) {
	Create(&businessCardBinder->businessCards);
	businessCardBinder->length = 0;
	businessCardBinder->current = NULL;
}


/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
ULong Load(BusinessCardBinder *businessCardBinder);

/*
�Լ���Ī : TakeIn
��    �� : ���԰���ö�� �Է¹��� ������ �����.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* TakeIn(BusinessCardBinder *businessCardBinder, BusinessCard businessCard) {
	Node *index;

	index = AppendFromTail(&businessCardBinder->businessCards, &businessCard, sizeof(BusinessCard));
	businessCardBinder->length++;
	businessCardBinder->current = (BusinessCard*)(index + 1);

	return businessCardBinder->current;
}

/*
�Լ���Ī : Find
��    �� : ���԰���ö���� �Է¹��� ����� ��ġ�ϴ� ���Ե�� ������ ����Ѵ�.
��    �� : ����
��    �� : ���Ե�, ����
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard* *(*indexes), ULong *count) {
	Node* (*nodeIndexes);
	ULong i = 0;

	*indexes = (BusinessCard* (*))calloc(businessCardBinder->length, sizeof(BusinessCard*));
	LinearSearchDuplicate(&businessCardBinder->businessCards, name, &nodeIndexes, count, CompareNames);
	while (i < *count) {
		(*indexes)[i] = (BusinessCard*)(nodeIndexes[i] + 1);
		i++;
	}
	if (nodeIndexes != NULL) {
		free(nodeIndexes);
		nodeIndexes = NULL;
	}
}

/*
�Լ���Ī : FindByCompanyName
��    �� : ���԰���ö���� �Է¹��� ��ȣ�� ã�Ƽ� ���Ը�ũ�� ����Ѵ�.
��    �� : ��ȣ
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*companyName)) {
	BusinessCard *index;
	Node *nodeIndex;

	nodeIndex = LinearSearchUnique(&businessCardBinder->businessCards, companyName, CompareCompanyNames);
	index = (BusinessCard*)(nodeIndex + 1);

	return index;
}

/*
�Լ���Ī : TakeOut
��    �� : ���԰���ö���� �Է¹��� ���Ը�ũ�� �ش��ϴ� ������ ����Ѵ�.
��    �� : ���Ը�ũ
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index) {
	Node *nodeIndex;
	BusinessCard businessCard;

	nodeIndex = LinearSearchUnique(&businessCardBinder->businessCards, index, CompareIndexes);
	GetAt(&businessCardBinder->businessCards, nodeIndex, &businessCard, sizeof(BusinessCard));
	Delete(&businessCardBinder->businessCards, nodeIndex);
	businessCardBinder->length--;
	businessCardBinder->current = (BusinessCard*)(businessCardBinder->businessCards.current + 1);

	return businessCard;
}

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard BusinessCardBinder_GetAt(BusinessCardBinder *businessCardBinder, BusinessCard *index);

/*
�Լ���Ī : BusinessCardBinder_First
��    �� : ���԰���ö�� ó�� �������� �̵��ϰ� ���Ը�ũ�� ����Ѵ�.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBinder_First(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = First(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
�Լ���Ī : BusinessCardBinder_Previous
��    �� : ���԰���ö���� ���� �������� �̵��ϰ� ���Ը�ũ�� ����Ѵ�.
��    �� : ����
��    �� : ���� ��ũ
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Previous(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = Previous(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
�Լ���Ī : BusinessCardBInder_Next
��    �� : ���԰���ö���� ���� �������� �̵��ϰ� ���Ը�Ŭ�� ����Ѵ�.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Next(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = Next(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
�Լ���Ī : BusinessCardBinder_Last
��    �� : ���԰���ö ������ �������� �̵��ϰ� ���Ը�ũ�� ����Ѵ�.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Last(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = Last(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
ULong Save(BusinessCardBinder *businessCardBinder);

/*
�Լ���Ī : BusinessCardBinder_Destroy
��    �� : ���԰���ö�� �����.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
void BusinessCardBinder_Destroy(BusinessCardBinder *businessCardBinder) {
	Destroy(&businessCardBinder->businessCards);
}


/*
�Լ���Ī : CompareNames
��    �� : ���԰� ������ �Է¹ް� ������ ����� ������ ���Ѵ�.
��    �� : ����, ����
��    �� : �񱳰��
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
int CompareNames(void *one, void *other) {
	return strcmp( ((BusinessCard*)one)->personal.name, (char*)other );
}

/*
�Լ���Ī : CompareCompanyNames
��    �� : ���԰� ��ȣ�� �Է¹ް� ������ ��ȣ�� ��ȣ�� ���� ����� ����Ѵ�.
��    �� : ���Ը�ũ, ��ȣ
��    �� : �񱳰��
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
int CompareCompanyNames(void *one, void *other) {
	return strcmp(((BusinessCard*)one)->company.name, (char*)other);
}

/*
�Լ���Ī : CompareIndexes
��    �� : �Է¹��� ��帵ũ�� ��帵ũ�� ���ؼ� ����� ����Ѵ�.
��    �� : ��帵ũ, ��帵ũ
��    �� : �񱳰��
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
int CompareIndexes(void *one, void *other) {
	int ret = -1;
	if (one == other) {
		return 0;
	}
	return ret;
}