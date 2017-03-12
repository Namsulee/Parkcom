//PostalBook.h
/*
파일 명칭 : PostalBook.h
기    능 : 우편번호부찾기 기능을 제공한다.
작 성 자 : Joey
작성 일자 : 2017/03/12
*/

#ifndef _POSTALBOOK_H
#define _POSTALBOOK_H
#include "Array.h"

//사용자정의 자료형 정의
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


//함수 선언들
void PostalBook_Create(PostalBook *postalBook, ULong capacity);
ULong PostalBook_Load(PostalBook *postalBook);
void PostalBook_Find(PostalBook *postalBook, char(*inputDong), ULong *(*indexes), ULong *count);
void PostalBook_Destroy(PostalBook *postalBook);

void PostalBook_GetAt(PostalBook *postalBook, ULong index);
int CompareDongs(void *one, void *other);
#endif //_POSTALBOOK_H