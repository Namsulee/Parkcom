//Date.h

#ifndef _DATE_H
#define _DATA_H

enum Month {JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12};
enum WeekDay {SUN = 0, MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6};
typedef unsigned short int UShort;

class Date {
public:	//operation들은 public으로 한다
	Date();									//기본 생성자
	~Date();								//소멸자
	Date(UShort year, UShort month, UShort day);	//매개변수 생성자 오버로딩 1999, FEB, 25
	Date(char(*date));								//매개변수 생성자 오버로딩 "19971212"
	Date(const Date& source);				//복사생성자
	static Date Today();					//static 정적 멤버
	operator char*();						//형변환 함수

	Date Yesterday();
	Date& operator--();						//전위 - 연산자오버로딩
	Date operator--(int);					//후위 - 연산자오버로딩

	Date Tomorrow();
	Date& operator++();						//전위 - 연산자오버로딩
	Date operator++(int);					//후위 - 연산자오버로딩

	Date PreviousDate(UShort days);
	Date operator-(UShort days);			//연산자오버로딩

	Date NextDate(UShort days);
	Date operator+(UShort days);			//연산자오버로딩

	bool IsEquals(const Date& other);
	bool operator==(const Date& other);		//연산자오버로딩

	bool IsNotEquals(const Date& other);
	bool operator!=(const Date& other);		//연산자오버로딩

	bool IsGreaterThan(const Date& other);
	bool operator>(const Date& other);		//연산자오버로딩
	bool operator>=(const Date& other);		//연산자오버로딩

	bool IsLessThan(const Date& other);
	bool operator<(const Date& other);		//연산자오버로딩
	bool operator<=(const Date& other);		//연산자오버로딩

	Date& operator=(const Date& source);	//치환연산자

	// attribute들에 대한 Get 함수들 -> inline 함수로 구현
	UShort GetYear() const;
	Month GetMonth() const;
	UShort GetDay() const;
	WeekDay GetWeekDay() const;

private:	//attribute들은 private으로 한다
	UShort year;
	Month month;
	UShort day;
	WeekDay weekDay;
};

// attribute들에 대해서 inline함수들로 구현한다.
inline UShort Date::GetYear() const {
	return this->year;
}

inline Month Date::GetMonth() const {
	return this->month;
}

inline UShort Date::GetDay() const {
	return this->day;
}

inline WeekDay Date::GetWeekDay() const {
	return this->weekDay;
}

#endif //_DATE_H