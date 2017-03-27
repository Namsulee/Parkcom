//Date.c
/*
파일 명칭 : Date.c
기     능 : 날짜에 대한 기능을 제공한다.
작 성 자 : Joey
작성 일자 : 2017/03/27
*/

#include "Date.h"
#include <time.h> //time관련된 함수 사용

//함수정의
/*
함수 명칭 : Create
기     능 : 날짜 객체를 생성한다.
입     력 : 없음
출     력 : 없음
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
함수 명칭 : Today
기     능 : 오늘 날짜를 구하고 출력한다.
입     력 : 없음
출     력 : 오늘 날짜
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
함수 명칭 : Yesterday
기     능 : 어제 날짜를 구하고, 출력한다.
입     력 : 없음
출     력 : 어제 날짜
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
함수 명칭 : Tommorrow
기     능 : 내일 날짜를 구하고 출력한다.
입     력 : 없음
출     력 : 내일 날짜
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
함수 명칭 : PreviousDate
기     능 : 이전의 날짜를 구하고 출력한다.
입     력 : 없음
출     력 : 이전 날짜
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
함수 명칭 : NextDate
기     능 : 다음의 날짜를 구하고, 출력한다.
입     력 : 일수
출     력 : 다음 날짜
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
함수 명칭 : IsEqual
기     능 : 입력받은 날짜들이 같은지 확인하고 비교결과를 출력한다.
입     력 : 날짜
출     력 : 비교결과
*/
Boolean IsEqual(Date *date, Date *other) {
	Boolean ret = FALSE;
	if (date->year == other->year && date->month == other->month && date->day == other->day) {
		ret = TRUE;
	}
	return ret;
}
/*
함수 명칭 : IsNotEqual
기     능 : 입력받은 날짜들이 같지않은지 확인하고 비교결과를 출력한다.
입     력 : 날짜
출     력 : 비교결과
*/
Boolean IsNotEqual(Date *date, Date *other) {
	Boolean ret = FALSE;
	if (date->year != other->year || date->month != other->month || date->day != other->day) {
		ret = TRUE;
	}
	return ret;
}
/*
함수 명칭 : IsGreaterThen
기     능 : 입력받은 날짜보다 더 큰 날짜인지 확인하고, 결과를 출력한다.
입     력 : 날짜
출     력 : 비교결과
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
함수 명칭 : IsLesserThen
기     능 : 입력받은 날짜보다 더 작은 날짜인지 확인하고, 결과를 출력한다.
입     력 : 날짜
출     력 : 비교결과
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
함수 명칭 : Destroy
기     능 : 날짜를 해제한다.
입     력 : 없음
출     력 : 없음
*/
void Destroy(Date *date) {

}
