#include "Date.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv) {
	Date today;
	today = Date::Today();

	cout << static_cast<char *>(today) << endl;

	Date someday("20180201");
	cout << static_cast<char *>(someday) << endl;

	return 0;
}