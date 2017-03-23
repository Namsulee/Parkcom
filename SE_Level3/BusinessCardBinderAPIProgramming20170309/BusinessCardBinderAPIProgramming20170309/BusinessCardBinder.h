//BusinessCardBinder.h
#ifndef _BUSINDESSCARDBINDER_H
#define _BUSINESSCARDBINDER_H

//자료형 선언들
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

typedef struct _businessCard BusinessCard;
typedef struct _businessCard {
	Company company;
	Personal personal;
	BusinessCard *next;
}BusinessCard;

typedef struct _businessCardBinder {
	BusinessCard *first;
	ULong length;
	BusinessCard *current;
}BusinessCardBinder;

//함수선언
void Create(BusinessCardBinder *businessCardBinder);
BusinessCard* TakeIn(BusinessCardBinder *businessCardBinder, BusinessCard businessCard);
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard **(*indexes), ULong *count);
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index);
void Arrange(BusinessCardBinder *businessCardBinder);
void Destroy(BusinessCardBinder *businessCardBinder);
BusinessCard* First(BusinessCardBinder *businessCardBinder);
BusinessCard* Previous(BusinessCardBinder *businessCardBinder);
BusinessCard* Next(BusinessCardBinder *businessCardBinder);
BusinessCard* Last(BusinessCardBinder *businessCardBinder);
//신규추가 2017/03/23
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*name));
#endif //_BUSINESSCARDBINDER_H