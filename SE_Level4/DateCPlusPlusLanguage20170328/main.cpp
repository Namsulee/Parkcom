#include "Date.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv) {
	Date today;
	today = Date::Today();

	cout << static_cast<char *>(today) << endl;

	Date someday("20090803");
	cout << static_cast<char *>(someday) << endl;

	//아래 코드도 정상동작함
	/*char * str = Date::Today();
	cout << str << endl;*/

	return 0;
}