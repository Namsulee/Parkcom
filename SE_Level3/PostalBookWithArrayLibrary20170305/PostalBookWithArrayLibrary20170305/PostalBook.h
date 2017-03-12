//PostalBook.h
/*
���� ��Ī : PostalBook.h
��    �� : �����ȣ��ã�� ����� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/

#ifndef _POSTALBOOK_H
#define _POSTALBOOK_H
#include "Array.h"

//��������� �ڷ��� ����
typedef unsigned long int ULong;

typedef struct _address {
	char zipcode[8];
	char sido[5];
	char gugun[18];
	char dong[27];
	char ri[16];
	char bldg[43];
	char stBunji[10];
	char edBunji[10];
	char seq[6];
}Address;

typedef struct _postalBook{
	Address (*addresses);
	ULong capacity;
	ULong length;
}PostalBook;


//�Լ� �����
void PostalBook_Create(PostalBook *postalBook, ULong capacity);
ULong PostalBook_Load(PostalBook *postalBook);
void PostalBook_Find(PostalBook *postalBook, char(*inputDong), ULong *(*indexes), ULong *count);
void PostalBook_Destroy(PostalBook *postalBook);

void PostalBook_GetAt(PostalBook *postalBook, ULong index);
int CompareDongs(void *one, void *other);
#endif //_POSTALBOOK_H