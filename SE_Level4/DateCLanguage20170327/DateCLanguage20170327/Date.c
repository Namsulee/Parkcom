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
기     능 : 날짜에서 오늘을 출력한다.
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
기     능 : 어제 날짜를 출력한다.
입     력 : 없음
출     력 : 어제 날짜
*/
Date Yesterday(Date *date) {

}
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Date Tommorrow(Date *date);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Date PreviousDate(Date *date);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Date NextDate(Date *date);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Boolean IsEqual(Date *date, Date *other);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Boolean IsNotEqual(Date *date, Date *other);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Boolean IsGreaterThen(Date *date, Date *other);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
Boolean IsLesserThen(Date *date, Date *other);
/*
함수 명칭 :
기     능 :
입     력 :
출     력 :
*/
void Destroy(Date *date);
