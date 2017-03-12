//AddressBook.h
#ifndef _ADDRESSBOOK_H
#define _ADDRESSsBOOK_H
#include "Array.h"

//자료형 선언
typedef signed long int Long;

typedef struct _personal {
	char name[11];
	char address[64];
	char telephoneNumber[12];
	char emailAddress[64];
}Personal;

typedef struct _addressBook{
	Array personals;
	Long capacity;
	Long length;
}AddressBook;

//함수선언
void AddressBook_Create(AddressBook *addressBook, Long capacity);
Long Load(AddressBook *addressBook);
Long Record(AddressBook *addressBook, char(*name), char(*address), char(*telephoneNumber), char(*emailAddress));
void Find(AddressBook *addressBook, char(*name), Long *(*indexes), Long *count);
Personal AddressBook_GetAt(AddressBook *addressBook, Long index);
Long Correct(AddressBook *addressBook, Long index, char(*address), char(*telephoneNumber), char(*emailAddress));
Long Erase(AddressBook *addressBook, Long index);
void Arrange(AddressBook *addressBook);
void AddressBook_Destroy(AddressBook *addressBook);
Long Save(AddressBook *addressBook);

//비교함수 추가
int CompareNames(void *one, void *other);
int ComparePersonals(void *one, void *other);
#endif