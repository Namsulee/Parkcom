//PostalBook.h
/*
파일 명칭 : PostalBook.h
기    능 : 우편번호부찾기 기능을 제공한다.
작 성 자 : Joey
작성 일자 : 2017/02/28
*/

#ifndef _POSTALBOOK_H
#define _POSTALBOOK_H

//상수정의들
#define ZIPCODE 8
#define SIDO 5
#define GUGUN 18
#define DONG 27
#define RI 16
#define BLDG 43
#define ST_BUNJI 10
#define ED_BUNJI 10
#define SEQ 6

//사용자정의 자료형 정의
typedef unsigned long int ULong;

typedef struct _address {
	char zipcode[ZIPCODE];
	char sido[SIDO];
	char gugun[GUGUN];
	char dong[DONG];
	char ri[RI];
	char bldg[BLDG];
	char stBunji[ST_BUNJI];
	char edBunji[ED_BUNJI];
	char seq[SEQ];
}Address;

typedef struct _postalBook{
	Address (*addresses);
	ULong capacity;
	ULong length;
}PostalBook;


//함수 선언들
void PostalBookCreate(PostalBook *postalBook, ULong capacity);
ULong PostalBookLoad(PostalBook *postalBook);
void PostalBookFind(PostalBook *postalBook, char(*inputDong), ULong *(*indexes), ULong *count);
void PostalBookDestroy(PostalBook *postalBook);
#endif //_POSTALBOOK_H