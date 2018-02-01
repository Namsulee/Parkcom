//Date.cpp

#include "Date.h"
#include <ctime>
#include <iostream>
using namespace std;

Date::Date() {
	this->year = 1900;
	this->month = JAN;
	this->day = 1;
	this->weekDay = MON;
}

Date::~Date() {

}

Date::Date(UShort year, UShort month, UShort day) {
	struct tm date = { 0, };
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	mktime(&date);
	this->year = date.tm_year + 1900;
	this->month = static_cast<Month>(date.tm_mon + 1);
	this->day = date.tm_mday;
	this->weekDay = static_cast<WeekDay>(date.tm_wday);
}

Date::Date(const Date& source) {
	this->year = source.year;	//source가 실제는 주소지만 우리는 값으로 생각한다.
	this->month = source.month;
	this->day = source.day;
	this->weekDay = source.weekDay;
}

Date::Date(char(*date)) {	//"19970125"
	struct tm temp = { 0, };
	sscanf(date, "%4d%02d%02d", &temp.tm_year, &temp.tm_mon, &temp.tm_mday);
	temp.tm_year -= 1900;
	temp.tm_mon -=  1;
	
	mktime(&temp);
	this->year = temp.tm_year + 1900;
	this->month = static_cast<Month>(temp.tm_mon + 1);
	this->day = temp.tm_mday;
	this->weekDay = static_cast<WeekDay>(temp.tm_wday);
}

Date Date::Today() {
	time_t timer;
	struct tm *today;
	Date today_;
	time(&timer);
	today = localtime(&timer);
	today_.year = today->tm_year + 1900;
	today_.month = static_cast<Month>(today->tm_mon + 1);
	today_.day = today->tm_mday;
	today_.weekDay = static_cast<WeekDay>(today->tm_wday);
	return today_;
}

Date::operator char*() {	//"19990215" 형식으로 출력
	static char buffer[9];
	sprintf(buffer, "%4d%02d%02d", this->year, this->month, this->day);
	return buffer;
}

Date Date::Yesterday() {
	struct tm yesterday = { 0, };
	Date yesterday_;
	yesterday.tm_year = this->year - 1900;
	yesterday.tm_mon = this->month - 1;
	yesterday.tm_mday = this->day - 1;
	mktime(&yesterday);
	yesterday_.year = yesterday.tm_year + 1900;
	yesterday_.month = static_cast<Month>(yesterday.tm_mon + 1);
	yesterday_.day = yesterday.tm_mday;
	yesterday_.weekDay = static_cast<WeekDay>(yesterday.tm_wday);
	return yesterday_;
}

Date& Date::operator--() {
	struct tm yesterday = { 0, };
	yesterday.tm_year = this->year - 1900;
	yesterday.tm_mon = this->month - 1;
	yesterday.tm_mday = this->day - 1;
	mktime(&yesterday);
	this->year = yesterday.tm_year + 1900;
	this->month = static_cast<Month>(yesterday.tm_mon + 1);
	this->day = yesterday.tm_mday;
	this->weekDay = static_cast<WeekDay>(yesterday.tm_wday);
	return *this; //stack에서 죽지 않는다.
}

Date Date::operator--(int) {
	struct tm yesterday = { 0, };
	Date temp(*this);	//this는 주소, *this는 값
	/*yesterday.tm_year = this->year - 1900;
	yesterday.tm_mon = this->month - 1;
	yesterday.tm_mday = this->day - 1;*/
	yesterday.tm_year = temp.year - 1900;
	yesterday.tm_mon = temp.month - 1;
	yesterday.tm_mday = temp.day - 1;
	mktime(&yesterday);
	temp.year = yesterday.tm_year + 1900;
	temp.month = static_cast<Month>(yesterday.tm_mon + 1);
	temp.day = yesterday.tm_mday;
	temp.weekDay = static_cast<WeekDay>(yesterday.tm_wday);
	return temp;
}

Date Date::Tomorrow() {
	struct tm tomorrow = { 0, };
	Date tomorrow_;
	tomorrow.tm_year = this->year - 1900;
	tomorrow.tm_mon = this->month - 1;
	tomorrow.tm_mday = this->day + 1;
	mktime(&tomorrow);
	tomorrow_.year = tomorrow.tm_year + 1900;
	tomorrow_.month = static_cast<Month>(tomorrow.tm_mon + 1);
	tomorrow_.day = tomorrow.tm_mday;
	tomorrow_.weekDay = static_cast<WeekDay>(tomorrow.tm_wday);
	return tomorrow_;
}

Date& Date::operator++() {
	struct tm tomorrow = { 0, };
	tomorrow.tm_year = this->year - 1900;
	tomorrow.tm_mon = this->month - 1;
	tomorrow.tm_mday = this->day + 1;
	mktime(&tomorrow);
	this->year = tomorrow.tm_year + 1900;
	this->month = static_cast<Month>(tomorrow.tm_mon + 1);
	this->day = tomorrow.tm_mday;
	this->weekDay = static_cast<WeekDay>(tomorrow.tm_wday);
	return *this;
}

Date Date::operator++(int) {
	struct tm tomorrow = { 0, };
	Date temp(*this);
	tomorrow.tm_year = this->year - 1900;
	tomorrow.tm_mon = this->month - 1;
	tomorrow.tm_mday = this->day + 1;
	mktime(&tomorrow);
	/*this->year = tomorrow.tm_year + 1900;
	this->month = static_cast<Month>(tomorrow.tm_mon + 1);
	this->day = tomorrow.tm_mday;
	this->weekDay = static_cast<WeekDay>(tomorrow.tm_wday);*/
	temp.year = tomorrow.tm_year + 1900;
	temp.month = static_cast<Month>(tomorrow.tm_mon + 1);
	temp.day = tomorrow.tm_mday;
	temp.weekDay = static_cast<WeekDay>(tomorrow.tm_wday);
	return temp;
}

Date Date::PreviousDate(UShort days) {
	struct tm previousDate = { 0, };
	Date previousDate_;
	previousDate.tm_year = this->year - 1900;
	previousDate.tm_mon = this->month - 1;
	previousDate.tm_mday = this->day - days;
	mktime(&previousDate);
	previousDate_.year = previousDate.tm_year + 1900;
	previousDate_.month = static_cast<Month>(previousDate.tm_mon + 1);
	previousDate_.day = previousDate.tm_mday;
	previousDate_.weekDay = static_cast<WeekDay>(previousDate.tm_wday);
	return previousDate_;
}

Date Date::operator-(UShort days) {
	struct tm previousDate = { 0, };
	Date previousDate_;
	previousDate.tm_year = this->year - 1900;
	previousDate.tm_mon = this->month - 1;
	previousDate.tm_mday = this->day - days;
	mktime(&previousDate);
	previousDate_.year = previousDate.tm_year + 1900;
	previousDate_.month = static_cast<Month>(previousDate.tm_mon + 1);
	previousDate_.day = previousDate.tm_mday;
	previousDate_.weekDay = static_cast<WeekDay>(previousDate.tm_wday);
	return previousDate_;
}

Date Date::NextDate(UShort days) {
	struct tm nextDate = { 0, };
	Date nextDate_;
	nextDate.tm_year = this->year - 1900;
	nextDate.tm_mon = this->month - 1;
	nextDate.tm_mday = this->day + days;
	mktime(&nextDate);
	nextDate_.year = nextDate.tm_year + 1900;
	nextDate_.month = static_cast<Month>(nextDate.tm_mon + 1);
	nextDate_.day = nextDate.tm_mday;
	nextDate_.weekDay = static_cast<WeekDay>(nextDate.tm_wday);
	return nextDate_;
}

Date Date::operator+(UShort days) {
	struct tm nextDate = { 0, };
	Date nextDate_;
	nextDate.tm_year = this->year - 1900;
	nextDate.tm_mon = this->month - 1;
	nextDate.tm_mday = this->day + days;
	mktime(&nextDate);
	nextDate_.year = nextDate.tm_year + 1900;
	nextDate_.month = static_cast<Month>(nextDate.tm_mon + 1);
	nextDate_.day = nextDate.tm_mday;
	nextDate_.weekDay = static_cast<WeekDay>(nextDate.tm_wday);
	return nextDate_;
}

bool Date::IsEquals(const Date& other) {
	bool ret = false;
	if (this->year == other.year &&
		this->month == other.month &&
		this->day == other.day) {
		ret = true;
	}
	return ret;
}

bool Date::operator==(const Date& other) {
	bool ret = false;
	if (this->year == other.year &&
		this->month == other.month &&
		this->day == other.day) {
		ret = true;
	}
	return ret;
}

bool Date::IsNotEquals(const Date& other) {
	bool ret = false;
	if (this->year != other.year ||
		this->month != other.month ||
		this->day != other.day) {
		ret = true;
	}
	return ret;
}

bool Date::operator!=(const Date& other) {
	bool ret = false;
	if (this->year != other.year ||
		this->month != other.month ||
		this->day != other.day) {
		ret = true;
	}
	return ret;
}

bool Date::IsGreaterThan(const Date& other) {
	bool ret = false;
	if (this->year > other.year) {
		ret = true;
	} else if (this->year == other.year &&
		this->month > other.month) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month == other.month &&
		this->day > other.day) {
		ret = true;
	}
	return ret;
}

bool Date::operator>(const Date& other) {
	bool ret = false;
	if (this->year > other.year) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month > other.month) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month == other.month &&
		this->day > other.day) {
		ret = true;
	}
	return ret;
}

bool Date::operator>=(const Date& other) {
	bool ret = false;
	if (this->year >= other.year) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month >= other.month) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month == other.month &&
		this->day >= other.day) {
		ret = true;
	}
	return ret;
}

bool Date::IsLessThan(const Date& other) {
	bool ret = false;
	if (this->year < other.year) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month < other.month) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month == other.month &&
		this->day < other.day) {
		ret = true;
	}
	return ret;
}

bool Date::operator<(const Date& other) {
	bool ret = false;
	if (this->year < other.year) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month < other.month) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month == other.month &&
		this->day < other.day) {
		ret = true;
	}
	return ret;
}

bool Date::operator<=(const Date& other) {
	bool ret = false;
	if (this->year <= other.year) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month <= other.month) {
		ret = true;
	}
	else if (this->year == other.year &&
		this->month == other.month &&
		this->day <= other.day) {
		ret = true;
	}
	return ret;
}

Date& Date::operator=(const Date& source) {	//치환연산자는 자동으로 생성되지만 반드시 정의를 하자.
	this->year = source.year;
	this->month = source.month;
	this->day = source.day;
	this->weekDay = source.weekDay;
	return *this;
}
