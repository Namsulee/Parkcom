//BusinessCardBinder.c
/*
���� ��Ī : BusinessCardBinder.c
��     �� : ������ �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
#include "BusinessCardBinder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(int argc, char*argv[]) {
//	BusinessCardBinder businessCardBinder;
//	BusinessCard businessCard;
//	BusinessCard *index;
//	BusinessCard* (*indexes);
//	ULong count;
//	ULong i;
//
//	//Create
//	Create(&businessCardBinder);
//	strcpy(businessCard.company.name, "�Ｚ");
//	strcpy(businessCard.company.telephoneNumber, "025879424");
//	strcpy(businessCard.company.url, "3.com");
//	strcpy(businessCard.company.address, "����� ���ʱ�");
//	strcpy(businessCard.company.faxNumber, "025879424");
//	strcpy(businessCard.personal.name, "��浿");
//	strcpy(businessCard.personal.position, "����");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0102222222");
//	strcpy(businessCard.personal.emailAddress, "kim@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	strcpy(businessCard.company.name, "����");
//	strcpy(businessCard.company.telephoneNumber, "035879424");
//	strcpy(businessCard.company.url, "9.com");
//	strcpy(businessCard.company.address, "����� ������");
//	strcpy(businessCard.company.faxNumber, "035879424");
//	strcpy(businessCard.personal.name, "ȫ�浿");
//	strcpy(businessCard.personal.position, "����");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0103333333");
//	strcpy(businessCard.personal.emailAddress, "hong@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	strcpy(businessCard.company.name, "����");
//	strcpy(businessCard.company.telephoneNumber, "045879424");
//	strcpy(businessCard.company.url, "ms.com");
//	strcpy(businessCard.company.address, "����� ���α�");
//	strcpy(businessCard.company.faxNumber, "045879424");
//	strcpy(businessCard.personal.name, "�̱浿");
//	strcpy(businessCard.personal.position, "�븮");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0104444444");
//	strcpy(businessCard.personal.emailAddress, "lee@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	strcpy(businessCard.company.name, "����");
//	strcpy(businessCard.company.telephoneNumber, "055879424");
//	strcpy(businessCard.company.url, "g.com");
//	strcpy(businessCard.company.address, "����� ��õ��");
//	strcpy(businessCard.company.faxNumber, "055879424");
//	strcpy(businessCard.personal.name, "ȫ�浿");
//	strcpy(businessCard.personal.position, "���");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0105555555");
//	strcpy(businessCard.personal.emailAddress, "hong2@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Find
//	Find(&businessCardBinder, "ȫ�浿", &indexes, &count);
//	i = 0;
//	while (i < count) {
//		printf("%s %s %s %s %s %s %s %s %s\n", 
//			indexes[i]->company.name, indexes[i]->company.telephoneNumber,
//			indexes[i]->company.url, indexes[i]->company.address, indexes[i]->company.faxNumber,
//			indexes[i]->personal.name, indexes[i]->personal.position, 
//			indexes[i]->personal.cellularPhoneNumber, indexes[i]->personal.emailAddress);
//		i++;
//	}
//
//	//TakeOut
//	businessCard = TakeOut(&businessCardBinder, indexes[0]);
//	printf("%s %s %s %s %s %s %s %s %s\n", businessCard.company.name, businessCard.company.telephoneNumber,
//		businessCard.company.url, businessCard.company.address, businessCard.company.faxNumber,
//		businessCard.personal.name, businessCard.personal.position, businessCard.personal.cellularPhoneNumber,
//		businessCard.personal.emailAddress);
//	if (indexes != NULL) {
//		free(indexes);
//		indexes = NULL;
//	}
//
//	//TakeIn
//	TakeIn(&businessCardBinder, businessCard);
//
//	//Arrange
//	Arrange(&businessCardBinder);
//
//	//First
//	index = First(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Next
//	index = Next(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Previous
//	index = Previous(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Last
//	index = Last(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Destroy
//	Destroy(&businessCardBinder);
//
//	return 0;
//}

/*
�Լ� ��Ī : Create
��    �� : ���԰���ö�� �غ��Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
void Create(BusinessCardBinder *businessCardBinder) {
	businessCardBinder->first = NULL;
	businessCardBinder->current = NULL;
	businessCardBinder->length = 0;
}

/*
�Լ� ��Ī : TakeIn
��    �� : ���԰���ö�� ������ �����ִ´�.
��    �� : ����
��    �� : ��ġ(���Ը�ũ)
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
BusinessCard* TakeIn(BusinessCardBinder *businessCardBinder, BusinessCard businessCard) {
	BusinessCard *previous = NULL;
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL) {
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	businessCardBinder->current = (BusinessCard *)malloc(sizeof(BusinessCard));
	(*businessCardBinder->current) = businessCard;
	if (previous != NULL) {
		previous->next = businessCardBinder->current;
	}
	else {
		businessCardBinder->first = businessCardBinder->current;
	}
	businessCardBinder->length++;

	return businessCardBinder->current;
}

/*
�Լ� ��Ī : Find
��    �� : ���԰���ö���� �Է¹��� ���������� ������ ã�´�.
��    �� : ����
��    �� : ��ũ��, ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard **(*indexes), ULong *count) {
	ULong i = 0;
	*count = 0;
	(*indexes) = (BusinessCard* (*))calloc(businessCardBinder->length, sizeof(BusinessCard*));
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL) {
		if (strcmp(businessCardBinder->current->personal.name, name) == 0) {
			(*indexes)[i] = businessCardBinder->current;
			i++;
			(*count)++;
		}
		businessCardBinder->current = businessCardBinder->current->next;
	}
}

/*
�Լ� ��Ī : TakeOut
��    �� : ���԰���ö���� ������ ������.
��    �� : ��ġ
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index){
	BusinessCard businessCard;
	BusinessCard *previous = NULL;
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != index) {
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	if (previous != NULL) {
		previous->next = businessCardBinder->current->next;
	}
	else {
		businessCardBinder->first = businessCardBinder->current->next;
	}

	if (index->next != NULL) {
		businessCardBinder->current = index->next;
	}
	else{
		businessCardBinder->current = previous;
	}

	index->next = NULL;
	businessCard = *index;
	if (index != NULL){
		free(index);
		index = NULL;
	}
	businessCardBinder->length--;
	return businessCard;
}

/*
�Լ� ��Ī : Arrange
��    �� : ����ö�� ���Ե��� ���������� �̿��ؼ� ������������ �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
void Arrange(BusinessCardBinder *businessCardBinder) {
	BusinessCard *previous;
	BusinessCard *next;
	BusinessCard *temp;
	ULong i = 1;
	ULong j;

	while (i < businessCardBinder->length) {
		previous = NULL;
		businessCardBinder->current = businessCardBinder->first;
		next = businessCardBinder->current->next;
		j = 1;
		while (j <= businessCardBinder->length - i) {
			if (strcmp(businessCardBinder->current->personal.name, next->personal.name) > 0) {
				if (previous != NULL) {
					temp = previous->next;
					previous->next = businessCardBinder->current->next;
				}
				else {
					temp = businessCardBinder->first;
					businessCardBinder->first = businessCardBinder->current->next;
				}
				businessCardBinder->current->next = next->next;
				next->next = temp;
				previous = next;
			}
			else {
				previous = businessCardBinder->current;
				businessCardBinder->current = next;
			}
			next = businessCardBinder->current->next;
			j++;
		}
		i++;
	}
}

/*
�Լ� ��Ī : Destroy
��    �� : ����ö�� �����.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
void Destroy(BusinessCardBinder *businessCardBinder) {
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL) {
		businessCardBinder->first = businessCardBinder->current->next;
		if (businessCardBinder->current != NULL) {
			free(businessCardBinder->current);
		}
		businessCardBinder->length--;;
		businessCardBinder->current = businessCardBinder->first;
	}
}

/*
�Լ� ��Ī : First
��    �� : ���԰���ö�� ó�� �������� �̵��Ѵ�.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
BusinessCard* First(BusinessCardBinder *businessCardBinder) {
	businessCardBinder->current = businessCardBinder->first;
	return businessCardBinder->current;
}

/*
�Լ� ��Ī : Previous
��    �� : ���԰���û�� ���� ��ġ ������ �������� �̵��Ѵ�.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
BusinessCard* Previous(BusinessCardBinder *businessCardBinder){
	BusinessCard *previous = NULL;
	BusinessCard *current = businessCardBinder->current;
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != current){
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	if (previous != NULL) {
		businessCardBinder->current = previous;
	}
	return businessCardBinder->current;
}

/*
�Լ� ��Ī : Next
��    �� : ���԰���ö�� ���� �������� �̵��Ѵ�.
��    �� : ����
��    �� : ���Ը�ũ
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
BusinessCard* Next(BusinessCardBinder *businessCardBinder) {
	BusinessCard *previous = businessCardBinder->current;
	businessCardBinder->current = businessCardBinder->current->next;
	if (businessCardBinder->current == NULL) {
		businessCardBinder->current = previous;
	}
	return businessCardBinder->current;
}

/*
�Լ� ��Ī : Last
��    �� : ���԰���ö�� ������ �������� �̵��Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/13
*/
BusinessCard* Last(BusinessCardBinder *businessCardBinder){
	BusinessCard *previous = NULL;
	if (businessCardBinder->current == NULL) {
		businessCardBinder->current = businessCardBinder->first;
	}
	while (businessCardBinder->current != NULL) {
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	businessCardBinder->current = previous;
	return businessCardBinder->current;
}

/*
�Լ� ��Ī : FindByCompanyName
��    �� : ���԰���ö�� ȸ���� ã�´�.(�ߺ�����)
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/23
*/
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*name)) {
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL && strcmp(businessCardBinder->current->company.name, name) != 0) {
		businessCardBinder->current = businessCardBinder->current->next;
	}
	return businessCardBinder->current;
}

/*
�Լ� ��Ī : Load
��    �� : ��ũ������ �о ���ε�� ȸ����� �߰��Ѵ�.(ȸ�� ��ȣ �ߺ�����)
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/25
*/
ULong Load(BusinessCardBinder *businessCardBinder) {
	Personal personal;
	Company company;
	ULong number;
	BusinessCard businessCard;
	BusinessCard *previous = NULL;
	ULong i;
	FILE *personalsFile;
	FILE *companiesFile;
	ULong flag1;
	ULong flag2;

	personalsFile = fopen("Personals.dat", "rb");
	companiesFile = fopen("Companies.dat", "rb");
	//1. ���� ������ ���� �ƴѵ��� �ݺ��Ѵ�.
	if (personalsFile != NULL && companiesFile != NULL) {
		//1.1. ��ȣ�� ������ �д´�.
		fread(&number, sizeof(ULong), 1, personalsFile);
		flag1 = fread(&personal, sizeof(Personal), 1, personalsFile);
		while (!feof(personalsFile) && flag1 != 0) {
			fseek(companiesFile, 0L, SEEK_SET);
			//1.2. ��ȣ�� �ִ� ȸ�縦 �д´�.
			i = 1;
			flag2 = fread(&company, sizeof(Company), 1, companiesFile);
			while (!feof(companiesFile) && flag2 != 0 && i < number) {
				i++;
				flag2 = fread(&company, sizeof(Company), 1, companiesFile);
			}
			//1.3. ������ �����.
			businessCard.personal = personal;
			businessCard.company = company;
			businessCard.next = NULL;
			//1.4. ����ö�� ������ ����.
			businessCardBinder->current = (BusinessCard*)malloc(sizeof(BusinessCard));
			*businessCardBinder->current = businessCard;
			if (previous != NULL) {
				previous->next = businessCardBinder->current;
			}
			else {
				businessCardBinder->first = businessCardBinder->current;
			}
			//1.5. ������ ������ ����.
			businessCardBinder->length++;
			previous = businessCardBinder->current;
			fread(&number, sizeof(Long), 1, personalsFile);
			flag1 = fread(&personal, sizeof(Personal), 1, personalsFile);
		}
		fclose(personalsFile);
		fclose(companiesFile);
	}
	//2. ������ ������ ����Ѵ�.
	return businessCardBinder->length;
	//3. ������.
}

/*
�Լ� ��Ī : Save
��    �� : ���԰���ö�� ���ε�� ȸ����� ��ũ���Ͽ� �����Ѵ�.(ȸ�� ��ȣ �ߺ�����)
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/25
*/
ULong Save(BusinessCardBinder *businessCardBinder) {
	ULong count = 0;
	Company company;
	ULong relationShip;
	FILE *personalsFile;
	FILE *companiesFile;
	ULong flag;

	personalsFile = fopen("Personals.dat", "wb");
	companiesFile = fopen("Companies.dat", "wb+");
	if (personalsFile != NULL && companiesFile != NULL) {
		businessCardBinder->current = businessCardBinder->first;
		//1.���԰���ö�� ���� �ƴѵ��� �ݺ��Ѵ�.
		while (businessCardBinder->current != NULL) {
			relationShip = 1;
			fseek(companiesFile, 0L, SEEK_SET);
			flag = fread(&company, sizeof(Company), 1, companiesFile);
			//1.1. ������ ��ȣ�� ���� ��ȣ�� ȸ�����Ͽ��� ã�´�.
			while (!feof(companiesFile) && flag != 0 && strcmp(businessCardBinder->current->company.name, company.name) != 0) {
				relationShip++;
				flag = fread(&company, sizeof(Company), 1, companiesFile);
			}
			//1.2. ������ ȸ�����Ͽ� ȸ�縦 ����Ѵ�.
			if (feof(companiesFile) && flag == 0) {
				fwrite(&businessCardBinder->current->company, sizeof(Company), 1, companiesFile);
			}
			//1.3. ��ȣ�� ������ ����Ѵ�.
			fwrite(&relationShip, sizeof(ULong), 1, personalsFile);
			fwrite(&businessCardBinder->current->personal, sizeof(Personal), 1, personalsFile);
			//1.4. ������ ������ ����.
			count++;
			businessCardBinder->current = businessCardBinder->current->next;
		}
		fclose(personalsFile);
		fclose(companiesFile);
	}
	//2. ������ ������ ����Ѵ�.
	return count;
	//3. ������.
}