//Date.h
#ifndef _DATE_H
#define _DATE_H

//사용자 정의 자료형
typedef unsigned short UShort;
typedef enum _boolean { FALSE = 0, TRUE = 1 }Boolean;
typedef enum _month { JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, TUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12 }Month;
typedef enum _weekDay {SUNDAY = 0, MONDAY = 1, TUESDAY = 2, WEDNESDAY = 3, THURSDAY = 4, FRIDAY = 5, SATURDAY = 6} WeekDay;
typedef struct _date Date;
typedef struct _date {
	UShort year;
	Month month;
	UShort day;
	WeekDay weekDay;
	Date(*Today)(Date*);
	Date(*Yesterday)(Date*);
	Date(*Tommorrow)(Date*);
	Date(*PreviousDate)(Date*, UShort);
	Date(*NextDate)(Date*, UShort);
	Boolean(*IsEqual)(Date*, Date*);
	Boolean(*IsNotEqual)(Date*, Date*);
	Boolean(*IsGreaterThen)(Date*, Date*);
	Boolean(*IsLesserThen)(Date*, Date*);
}Date;

//함수 선언
void Create(Date *date);
Date Today(Date *date);
Date Yesterday(Date *date);
Date Tommorrow(Date *date);
Date PreviousDate(Date *date, UShort days);
Date NextDate(Date *date, UShort days);
Boolean IsEqual(Date *date, Date *other);
Boolean IsNotEqual(Date *date, Date *other);
Boolean IsGreaterThen(Date *date, Date *other);
Boolean IsLesserThen(Date *date, Date *other);
void Destroy(Date *date);

#endif //_DATE_H
