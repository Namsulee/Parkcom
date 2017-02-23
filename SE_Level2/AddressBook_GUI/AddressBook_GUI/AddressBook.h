#ifndef _ADDRESSBOOK_H
#define _ADDRESSBOOK_H

//상수 선언들
#define NAME 11
#define ADDRESS 128
#define TELEPHONENUMBER 12
#define EMAILADDRESS 128

//사용자 정의 자료형
typedef signed long int Long;

typedef struct _personal{
	char name[NAME];
	char address[ADDRESS];
	char telephoneNumber[TELEPHONENUMBER];
	char emailAddress[EMAILADDRESS];
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