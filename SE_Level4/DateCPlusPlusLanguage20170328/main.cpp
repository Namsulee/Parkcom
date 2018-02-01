#include "Date.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv) {
	/*Date today;
	today = Date::Today();

	cout << static_cast<char *>(today) << endl;

	Date someday("20090803");
	cout << static_cast<char *>(someday) << endl;*/

	//�Ʒ� �ڵ嵵 ��������
	/*char * str = Date::Today();
	cout << str << endl;*/

	//1. "yyyymmdd"������ ������ Test
	Date yesterday("20180201");
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;

	//2. yyyy, Month, day �Ű����� ������ Test
	Date tomorrow(2018, FEB, 3);
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;

	//3. today Test
	Date today;
	today = Date::Today();	//�������� ȣ��
	cout << static_cast<char *>(today) << " " << today.GetWeekDay() << endl;

	//4. yesterday Test
	yesterday = today.Yesterday();
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;
	//5. ��������
	Date date;
	date = --yesterday;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;
	//6. ��������
	date = yesterday--;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(yesterday) << " " << yesterday.GetWeekDay() << endl;

	//7. tomorrow Test
	tomorrow = today.Tomorrow();
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;
	//8. ��������
	date = ++tomorrow;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;
	//9. ��������
	date = tomorrow++;
	cout << static_cast<char *>(date) << " " << date.GetWeekDay() << endl;
	cout << static_cast<char *>(tomorrow) << " " << tomorrow.GetWeekDay() << endl;

	//10. PreviousDate Test
	Date previousDate = today.PreviousDate(static_cast<UShort>(3));
	cout << static_cast<char *>(previousDate) << " " << previousDate.GetWeekDay() << endl;
	//11. -����
	previousDate = today - static_cast<UShort>(3);
	cout << static_cast<char *>(previousDate) << " " << previousDate.GetWeekDay() << endl;

	//12. NextDate Test
	Date nextDate = today.NextDate(static_cast<UShort>(4));
	cout << static_cast<char *>(nextDate) << " " << nextDate.GetWeekDay() << endl;
	//13. +����
	nextDate = today + static_cast<UShort>(4);
	cout << static_cast<char *>(nextDate) << " " << nextDate.GetWeekDay() << endl;

	Date birthDay(1997, JAN, 8);
	Date other("19970108");
	Date another(other);
	cout << static_cast<char *>(birthDay) << " " << birthDay.GetWeekDay() << endl;

	//14. ==
	if (another == other) {
		cout << "����" << endl;
	}
	
	//15. !=
	if (today != birthDay) {
		cout << "�ٸ���" << endl;
	}
	
	//16. >
	if (today > birthDay) {
		cout << "ũ��" << endl;
	}
	
	//17. >=
	if (today >= birthDay) {
		cout << "ũ�ų� ����" << endl;
	}

	//18. <
	if (birthDay < today) {
		cout << "�۴�" << endl;
	}

	//19. <=
	if (birthDay <= today) {
		cout << "�۰ų� ����" << endl;
	}
	return 0;
}