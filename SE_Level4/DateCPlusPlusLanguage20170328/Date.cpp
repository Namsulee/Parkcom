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
	sscanf(date, "%Y%m%d", &temp);
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
	yesterday.tm_year = this->month - 1900;
	yesterday.tm_mon = this->month - 1;
	yesterday.tm_mday = this->day - 1;
	mktime(&yesterday);
	temp.year = yesterday.tm_year + 1900;
	temp.month = static_cast<Month>(yesterday.tm_mon + 1);
	temp.day = yesterday.tm_mday;
	temp.weekDay = static_cast<WeekDay>(yesterday.tm_wday);
	return temp;
}

Date Date::Tomorrow() {

}

Date& Date::operator++() {

}

Date Date::operator++(int) {

}

Date Date::PreviousDate(UShort days) {

}

Date Date::operator-(UShort days) {

}

Date Date::NextDate(UShort days) {

}

Date Date::operator+(UShort days) {

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

}

bool Date::operator!=(const Date& other) {

}

bool Date::IsGreaterThan(const Date& other) {

}

bool Date::operator>(const Date& other) {

}

bool Date::operator>=(const Date& other) {

}

bool Date::IsLessThan(const Date& other) {

}

bool Date::operator<(const Date& other) {

}

bool Date::operator<=(const Date& other) {

}

Date& Date::operator=(const Date& source) {

}
