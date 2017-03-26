//BusinessCardBinder.c
#include "BusinessCardBinder.h"
#include <string.h>
#include <stdio.h>


//�����Լ�����
int main(int argc, char *argv[]) {
	BusinessCardBinder businessCardBinder;
	BusinessCard businessCard;
	BusinessCard *index;

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
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard* *(*indexes), ULong *count);

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*companyName));

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index);

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
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBinder_First(BusinessCardBinder *businessCardBinder);

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Previous(BusinessCardBinder *businessCardBinder);

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBInder_Next(BusinessCardBinder *businessCardBinder);

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
BusinessCard* BusinessCardBInder_Last(BusinessCardBinder *businessCardBinder);

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
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
int CompareNames(void *one, void *other);

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
int CompareCompanyNames(void *one, void *other);

/*
�Լ���Ī :
��    �� :
��    �� :
��    �� :
�� �� �� : Joey
�ۼ����� : 2017/03/26
*/
int CompareIndexes(void *one, void *other);