//Date.c
/*
���� ��Ī : Date.c
��     �� : ��¥�� ���� ����� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/27
*/

#include "Date.h"
#include <time.h> //time���õ� �Լ� ���

//�Լ�����
/*
�Լ� ��Ī : Create
��     �� : ��¥ ��ü�� �����Ѵ�.
��     �� : ����
��     �� : ����
*/
void Create(Date *date) {
	date->year = 1900;
	date->month = JAN;
	date->day = 1;
	date->weekDay = MONDAY;
	date->Today = Today;
	date->Yesterday = Yesterday;
	date->Tommorrow = Tommorrow;
	date->PreviousDate = PreviousDate;
	date->NextDate = NextDate;
	date->IsEqual = IsEqual;
	date->IsNotEqual = IsNotEqual;
	date->IsGreaterThen = IsGreaterThen;
	date->IsLesserThen = IsLesserThen;
}

/*
�Լ� ��Ī : Today
��     �� : ��¥���� ������ ����Ѵ�.
��     �� : ����
��     �� : ���� ��¥
*/
Date Today(Date *date) {
	time_t timer;
	struct tm *today;
	Date today_;
	Create(&today_);
	time(&timer);
	today = localtime(&timer);
	today_.year = today->tm_year + 1900;
	today_.month = (Month)(today->tm_mon + 1);
	today_.day = today->tm_mday;
	today_.weekDay = (WeekDay)(today->tm_wday);
	Destroy(&today_);
	return today_;
}
/*
�Լ� ��Ī : Yesterday
��     �� : ���� ��¥�� ����Ѵ�.
��     �� : ����
��     �� : ���� ��¥
*/
Date Yesterday(Date *date) {

}
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Date Tommorrow(Date *date);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Date PreviousDate(Date *date);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Date NextDate(Date *date);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Boolean IsEqual(Date *date, Date *other);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Boolean IsNotEqual(Date *date, Date *other);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Boolean IsGreaterThen(Date *date, Date *other);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
Boolean IsLesserThen(Date *date, Date *other);
/*
�Լ� ��Ī :
��     �� :
��     �� :
��     �� :
*/
void Destroy(Date *date);
