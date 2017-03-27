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
��     �� : ���� ��¥�� ���ϰ� ����Ѵ�.
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
��     �� : ���� ��¥�� ���ϰ�, ����Ѵ�.
��     �� : ����
��     �� : ���� ��¥
*/
Date Yesterday(Date *date) {
	struct tm yesterday = { 0, };
	Date yesterday_;
	Create(&yesterday_);
	yesterday.tm_year = date->year - 1900;
	yesterday.tm_mon = date->month - 1;
	yesterday.tm_mday = date->day - 1;
	mktime(&yesterday);
	yesterday_.year = yesterday.tm_year + 1900;
	yesterday_.month = (Month)(yesterday.tm_mon + 1);
	yesterday_.day = yesterday.tm_mday;
	yesterday_.weekDay = yesterday.tm_mday;
	Destroy(&yesterday_);
	return yesterday_;
}
/*
�Լ� ��Ī : Tommorrow
��     �� : ���� ��¥�� ���ϰ� ����Ѵ�.
��     �� : ����
��     �� : ���� ��¥
*/
Date Tommorrow(Date *date) {
	struct tm tommorrow = { 0, };
	Date tommorrow_;
	Create(&tommorrow_);
	tommorrow.tm_year = date->year - 1900;
	tommorrow.tm_mon = date->month - 1;
	tommorrow.tm_mday = date->day + 1;
	mktime(&tommorrow);
	tommorrow_.year = tommorrow.tm_year + 1900;
	tommorrow_.month = (Month)(tommorrow.tm_mon + 1);
	tommorrow_.day = tommorrow.tm_mday;
	tommorrow_.weekDay = tommorrow.tm_mday;
	Destroy(&tommorrow_);
	return tommorrow_;
}
/*
�Լ� ��Ī : PreviousDate
��     �� : ������ ��¥�� ���ϰ� ����Ѵ�.
��     �� : ����
��     �� : ���� ��¥
*/
Date PreviousDate(Date *date, UShort days) {
	struct tm previousDate = { 0, };
	Date previousDate_;
	Create(&previousDate_);
	previousDate.tm_year = date->year - 1900;
	previousDate.tm_mon = date->month - 1;
	previousDate.tm_mday = date->day - days;
	mktime(&previousDate);
	previousDate_.year = previousDate.tm_year + 1900;
	previousDate_.month = (Month)(previousDate.tm_mon + 1);
	previousDate_.day = previousDate.tm_mday;
	previousDate_.weekDay = previousDate.tm_mday;
	Destroy(&previousDate_);
	return previousDate_;
}
/*
�Լ� ��Ī : NextDate
��     �� : ������ ��¥�� ���ϰ�, ����Ѵ�.
��     �� : �ϼ�
��     �� : ���� ��¥
*/
Date NextDate(Date *date, UShort days) {
	struct tm nextDate = { 0, };
	Date nextDate_;
	Create(&nextDate_);
	nextDate.tm_year = date->year - 1900;
	nextDate.tm_mon = date->month - 1;
	nextDate.tm_mday = date->day + days;
	mktime(&nextDate);
	nextDate_.year = nextDate.tm_year + 1900;
	nextDate_.month = (Month)(nextDate.tm_mon + 1);
	nextDate_.day = nextDate.tm_mday;
	nextDate_.weekDay = nextDate.tm_mday;
	Destroy(&nextDate_);
	return nextDate_;
}
/*
�Լ� ��Ī : IsEqual
��     �� : �Է¹��� ��¥���� ������ Ȯ���ϰ� �񱳰���� ����Ѵ�.
��     �� : ��¥
��     �� : �񱳰��
*/
Boolean IsEqual(Date *date, Date *other) {
	Boolean ret = FALSE;
	if (date->year == other->year && date->month == other->month && date->day == other->day) {
		ret = TRUE;
	}
	return ret;
}
/*
�Լ� ��Ī : IsNotEqual
��     �� : �Է¹��� ��¥���� ���������� Ȯ���ϰ� �񱳰���� ����Ѵ�.
��     �� : ��¥
��     �� : �񱳰��
*/
Boolean IsNotEqual(Date *date, Date *other) {
	Boolean ret = FALSE;
	if (date->year != other->year || date->month != other->month || date->day != other->day) {
		ret = TRUE;
	}
	return ret;
}
/*
�Լ� ��Ī : IsGreaterThen
��     �� : �Է¹��� ��¥���� �� ū ��¥���� Ȯ���ϰ�, ����� ����Ѵ�.
��     �� : ��¥
��     �� : �񱳰��
*/
Boolean IsGreaterThen(Date *date, Date *other) {
	Boolean ret = FALSE;
	if (date->year > other->year) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month > other->month) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month == other->month && date->day > other->day) {
		ret = TRUE;
	}
	return ret;
}
/*
�Լ� ��Ī : IsLesserThen
��     �� : �Է¹��� ��¥���� �� ���� ��¥���� Ȯ���ϰ�, ����� ����Ѵ�.
��     �� : ��¥
��     �� : �񱳰��
*/
Boolean IsLesserThen(Date *date, Date *other) {
	Boolean ret = FALSE;
	if (date->year < other->year) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month < other->month) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month == other->month && date->day < other->day) {
		ret = TRUE;
	}
	return ret;
}
/*
�Լ� ��Ī : Destroy
��     �� : ��¥�� �����Ѵ�.
��     �� : ����
��     �� : ����
*/
void Destroy(Date *date) {

}
