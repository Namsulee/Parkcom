#include "Date.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv) {
	/*Date today;
	today = Date::Today();

	cout << static_cast<char *>(today) << endl;

	Date someday("20090803");
	cout << static_cast<char *>(someday) << endl;*/

	//아래 코드도 정상동작함
	/*char * str = Date::Today();
	cout << str << endl;*/

	//1. "yyyymmdd"형식의 생성자 Test
	Date yesterday("20180201");
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;

	//2. yyyy, Month, day 매개변수 생성자 Test
	Date tomorrow(2018, FEB, 3);
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;

	//3. today Test
	Date today;
	today = Date::Today();	//정적연산 호출
	cout << static_cast<char *>(today) << " " << today.GetWeekDay() << endl;

	//4. yesterday Test
	yesterday = today.Yesterday();
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;
	//5. 전위연산
	Date date;
	date = --yesterday;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;
	//6. 후위연산
	date = yesterday--;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;

	//7. tomorrow Test
	tomorrow = today.Tomorrow();
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;
	//8. 전위연산
	date = ++tomorrow;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;
	//9. 후위연산
	date = tomorrow++;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;

	//10. PreviousDate Test
	Date previousDate = today.PreviousDate(static_cast<UShort>(3));
	cout << static_cast<char *>(previousDate) << " " << previousDate.GetWeekDay() << endl;
	//11. -연산
	previousDate = today - static_cast<UShort>(3);
	cout << static_cast<char *>(previousDate) << " " << previousDate.GetWeekDay() << endl;

	//12. NextDate Test
	Date nextDate = today.NextDate(static_cast<UShort>(4));
	cout << static_cast<char *>(nextDate) << " " << nextDate.GetWeekDay() << endl;
	//13. +연산
	nextDate = today + static_cast<UShort>(4);
	cout << static_cast<char *>(nextDate) << " " << nextDate.GetWeekDay() << endl;

	Date birthDay(1997, JAN, 8);
	Date other("19970108");
	Date another(other);
	cout << static_cast<char *>(birthDay) << " " << birthDay.GetWeekDay() << endl;

	//14. ==
	if (another == other) {
		cout << "같다" << endl;
	}
	
	//15. !=
	if (today != birthDay) {
		cout << "다르다" << endl;
	}
	
	//16. >
	if (today > birthDay) {
		cout << "크다" << endl;
	}
	
	//17. >=
	if (today >= birthDay) {
		cout << "크거나 같다" << endl;
	}

	//18. <
	if (birthDay < today) {
		cout << "작다" << endl;
	}

	//19. <=
	if (birthDay <= today) {
		cout << "작거나 같다" << endl;
	}
	return 0;
}