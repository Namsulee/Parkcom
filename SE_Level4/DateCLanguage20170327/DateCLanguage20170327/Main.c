//Main.c
/*
파일 명칭 : Main.c
기     능 : 날짜 기능을 제공한다.
작 성 자 : Joey
작성 일자 : 2017/03/27
*/

#include "Date.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	Date date;
	Date today;
	Date yesterday;
	Date tommorrow;
	Date previousDate;
	Date nextDate;
	Boolean ret;

	//생성한다.
	Create(&date);
	Create(&today);
	Create(&yesterday);
	Create(&tommorrow);
	Create(&previousDate);
	Create(&nextDate);

	//오늘
	today = date.Today(&date);
	printf("%4d-%02d-%02d-", today.year, today.month, today.day);
	switch(today.weekDay) {
		case SUNDAY: printf("일요일\n"); break;
		case MONDAY: printf("월요일\n"); break;
		case TUESDAY: printf("화요일\n"); break;
		case WEDNESDAY: printf("수요일\n"); break;
		case THURSDAY: printf("목요일\n"); break;
		case FRIDAY: printf("금요일\n"); break;
		case SATURDAY: printf("토요일\n"); break;
		default: break;
	}

	//어제
	yesterday = today.Yesterday(&today);
	printf("%4d-%02d-%02d-", yesterday.year, yesterday.month, yesterday.day);
	switch (yesterday.weekDay) {
		case SUNDAY: printf("일요일\n"); break;
		case MONDAY: printf("월요일\n"); break;
		case TUESDAY: printf("화요일\n"); break;
		case WEDNESDAY: printf("수요일\n"); break;
		case THURSDAY: printf("목요일\n"); break;
		case FRIDAY: printf("금요일\n"); break;
		case SATURDAY: printf("토요일\n"); break;
		default: break;
	}

	//내일
	tommorrow = yesterday.Tommorrow(&yesterday);
	printf("%4d-%02d-%02d-", tommorrow.year, tommorrow.month, tommorrow.day);
	switch (tommorrow.weekDay) {
		case SUNDAY: printf("일요일\n"); break;
		case MONDAY: printf("월요일\n"); break;
		case TUESDAY: printf("화요일\n"); break;
		case WEDNESDAY: printf("수요일\n"); break;
		case THURSDAY: printf("목요일\n"); break;
		case FRIDAY: printf("금요일\n"); break;
		case SATURDAY: printf("토요일\n"); break;
		default: break;
	}

	//이전날짜
	previousDate = today.PreviousDate(&today, 3);
	printf("%4d-%02d-%02d-", previousDate.year, previousDate.month, previousDate.day);
	switch (previousDate.weekDay) {
		case SUNDAY: printf("일요일\n"); break;
		case MONDAY: printf("월요일\n"); break;
		case TUESDAY: printf("화요일\n"); break;
		case WEDNESDAY: printf("수요일\n"); break;
		case THURSDAY: printf("목요일\n"); break;
		case FRIDAY: printf("금요일\n"); break;
		case SATURDAY: printf("토요일\n"); break;
		default: break;
	}
	
	//이후날짜
	nextDate = today.NextDate(&today, 4);
	printf("%4d-%02d-%02d-", nextDate.year, nextDate.month, nextDate.day);
	switch (nextDate.weekDay) {
		case SUNDAY: printf("일요일\n"); break;
		case MONDAY: printf("월요일\n"); break;
		case TUESDAY: printf("화요일\n"); break;
		case WEDNESDAY: printf("수요일\n"); break;
		case THURSDAY: printf("목요일\n"); break;
		case FRIDAY: printf("금요일\n"); break;
		case SATURDAY: printf("토요일\n"); break;
		default: break;
	}

	//같은지
	ret = tommorrow.IsEqual(&tommorrow, &today);
	if (ret == TRUE) {
		printf("같습니다.\n");
	}
	else {
		printf("같지 않습니다.\n");
	}

	//다른지
	ret = yesterday.IsNotEqual(&yesterday, &today);
	if (ret == TRUE) {
		printf("다릅니다.\n");
	}
	else {
		printf("다르지 않습니다.\n");
	}

	//더큰지
	ret = today.IsGreaterThen(&today, &yesterday);
	if (ret == TRUE) {
		printf("더 나중입니다.\n");
	}
	else {
		printf("더 나중이 아닙니다.\n");
	}

	//더작은지
	ret = previousDate.IsLesserThen(&previousDate, &nextDate);
	if (ret == TRUE) {
		printf("더 이전입니다.\n");
	}
	else {
		printf("더 이전이 아닙니다.\n");
	}

	//지운다.
	Destroy(&date);
	Destroy(&today);
	Destroy(&yesterday);
	Destroy(&tommorrow);
	Destroy(&previousDate);
	Destroy(&nextDate);

	return 0;
}