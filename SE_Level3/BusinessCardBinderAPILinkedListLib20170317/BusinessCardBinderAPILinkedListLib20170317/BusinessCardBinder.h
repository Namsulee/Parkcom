//BusinessCardBinder.h
#ifndef _BUSINESSCARDBINDER_H
#define _BUSINESSCARDBINDER_H
#include "LinkedList.h"

//����� ���� �ڷ���
typedef unsigned long int ULong;
typedef struct _company {
	char name[64];
	char telephoneNumber[12];
	char url[256];
	char address[256];
	char faxNumber[12];
}Company;
typedef struct _personal {
	char name[11];
	char position[256];
	char cellularPhoneNumber[12];
	char emailAddress[256];
}Personal;
typedef struct _businessCard {
	Personal personal;
	Company company;
}BusinessCard;
typedef struct _businessCardBinder {
	LinkedList businessCards;
	ULong length;
	BusinessCard *current;
}BusinessCardBinder;

int main(int argc, char * argv[]);

//�Լ�����
void BusinessCardBinder_Create(BusinessCardBinder *businessCardBinder);
ULong Load(BusinessCardBinder *businessCardBinder);
BusinessCard* TakeIn(BusinessCardBinder *businessCardBinder, BusinessCard businessCard);
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard* *(*indexes), ULong *count);
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*companyName));
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index);
BusinessCard BusinessCardBinder_GetAt(BusinessCardBinder *businessCardBinder, BusinessCard *index);
BusinessCard* BusinessCardBinder_First(BusinessCardBinder *businessCardBinder);
BusinessCard* BusinessCardBinder_Previous(BusinessCardBinder *businessCardBinder);
BusinessCard* BusinessCardBinder_Next(BusinessCardBinder *businessCardBinder);
BusinessCard* BusinessCardBinder_Last(BusinessCardBinder *businessCardBinder);
ULong Save(BusinessCardBinder *businessCardBinder);
void BusinessCardBinder_Destroy(BusinessCardBinder *businessCardBinder);

//���Լ�����
int CompareNames(void *one, void *other);
int CompareCompanyNames(void *one, void *other);
int CompareIndexes(void *one, void *other);

#endif //_BUSINESSCARDBINDER_H