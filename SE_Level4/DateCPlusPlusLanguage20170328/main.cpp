#include "Date.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv) {
	Date today;
	today = Date::Today();

	cout << static_cast<char *>(today) << endl;

	Date someday("20090803");
	cout << static_cast<char *>(someday) << endl;

	//�Ʒ� �ڵ嵵 ��������
	/*char * str = Date::Today();
	cout << str << endl;*/

	return 0;
}