//Date.h

#ifndef _DATE_H
#define _DATA_H

enum Month {JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12};
enum WeekDay {SUN = 0, MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6};
typedef unsigned short int UShort;

class Date {
public:	//operation���� public���� �Ѵ�
	Date();									//�⺻ ������
	~Date();								//�Ҹ���
	Date(UShort year, UShort month, UShort day);	//�Ű����� ������ �����ε� 1999, FEB, 25
	Date(char(*date));								//�Ű����� ������ �����ε� "19971212"
	Date(const Date& source);				//���������
	static Date Today();					//static ���� ���
	operator char*();						//����ȯ �Լ�

	Date Yesterday();
	Date& operator--();						//���� - �����ڿ����ε�
	Date operator--(int);					//���� - �����ڿ����ε�

	Date Tomorrow();
	Date& operator++();						//���� - �����ڿ����ε�
	Date operator++(int);					//���� - �����ڿ����ε�

	Date PreviousDate(UShort days);
	Date operator-(UShort days);			//�����ڿ����ε�

	Date NextDate(UShort days);
	Date operator+(UShort days);			//�����ڿ����ε�

	bool IsEquals(const Date& other);
	bool operator==(const Date& other);		//�����ڿ����ε�

	bool IsNotEquals(const Date& other);
	bool operator!=(const Date& other);		//�����ڿ����ε�

	bool IsGreaterThan(const Date& other);
	bool operator>(const Date& other);		//�����ڿ����ε�
	bool operator>=(const Date& other);		//�����ڿ����ε�

	bool IsLessThan(const Date& other);
	bool operator<(const Date& other);		//�����ڿ����ε�
	bool operator<=(const Date& other);		//�����ڿ����ε�

	Date& operator=(const Date& source);	//ġȯ������

	// attribute�鿡 ���� Get �Լ��� -> inline �Լ��� ����
	UShort GetYear() const;
	Month GetMonth() const;
	UShort GetDay() const;
	WeekDay GetWeekDay() const;

private:	//attribute���� private���� �Ѵ�
	UShort year;
	Month month;
	UShort day;
	WeekDay weekDay;
};

// attribute�鿡 ���ؼ� inline�Լ���� �����Ѵ�.
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