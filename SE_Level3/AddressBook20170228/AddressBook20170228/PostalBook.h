//PostalBook.h
/*
���� ��Ī : PostalBook.h
��    �� : �����ȣ��ã�� ����� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/02/28
*/

#ifndef _POSTALBOOK_H
#define _POSTALBOOK_H

//������ǵ�
#define ZIPCODE 8
#define SIDO 5
#define GUGUN 18
#define DONG 27
#define RI 16
#define BLDG 43
#define ST_BUNJI 10
#define ED_BUNJI 10
#define SEQ 6

//��������� �ڷ��� ����
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


//�Լ� �����
void PostalBookCreate(PostalBook *postalBook, ULong capacity);
ULong PostalBookLoad(PostalBook *postalBook);
void PostalBookFind(PostalBook *postalBook, char(*inputDong), ULong *(*indexes), ULong *count);
void PostalBookDestroy(PostalBook *postalBook);
#endif //_POSTALBOOK_H