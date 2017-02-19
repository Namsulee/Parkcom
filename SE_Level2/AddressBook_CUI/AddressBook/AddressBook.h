#ifndef _ADDRESSBOOK_H
#define _ADDRESSBOOK_H

//사용자 정의 자료형
typedef signed long int Long;

typedef struct _personal{
	char name[11];
	char address[128];
	char telephoneNumber[12];
	char emailAddress[128];
} Personal;

typedef struct _addressBook {
	Personal (*personals);
	Long capacity;
	Long length;
} AddressBook;

//함수 선언
Long Record(AddressBook *addressBook, char(*name), char(*address), char(*telephoneNumber), char(*emailAddress));
void Find(AddressBook *addressBook, char (*name), Long *(*indexes), Long (*count));
Long Correct(AddressBook *addressBook, Long index, char (*address), char (*telephoneNumber), char (*emailAddress));
Long Erase(AddressBook *addressBook, Long index);
void Arrange(AddressBook *addressBook);
void Create(AddressBook *addressBook, Long capacity);
void Destroy(AddressBook *addressBook);

#endif //_ADDRESSBOOK_H