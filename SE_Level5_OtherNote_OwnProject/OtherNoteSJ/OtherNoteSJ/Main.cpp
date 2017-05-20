

//#include <iostream>
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	Memo memo;
//	Long index;
//	SingleCharacter singCharacter;
//
//	index = memo.Write('a');
//	singCharacter = memo.GetAt(index);
//	cout << singCharacter.GetValue() << endl;
//
//	index = memo.Write('b');
//	singCharacter = memo.GetAt(index);
//	cout << singCharacter.GetValue() << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main(int argc, char *argv[]) {
//	Memo memo;
//	Character *characterLink;
//	Long index;
//	string characters;
//
//	index = memo.Write("한");
//	characterLink = memo.GetAt(index);
//	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
//	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
//
//	index = memo.Write("글");
//	characterLink = memo.GetAt(index);
//	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
//	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
//
//	cout << characters << endl;
//
//	return 0;
//}



#include <iostream>
#include <string>
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
using namespace std;
int main(int argc, char *argv[]) {

	Memo memo;
	memo.Write('a');
	Line line = memo.GetAt(memo.GetRow());
	Character *characterLink = line.GetAt(line.GetColumn() - 1);
	string completeString;
	completeString = static_cast<SingleCharacter*>(characterLink)->GetValue();

	cout << completeString << endl;

	memo.Write("한");
	line = memo.GetAt(memo.GetRow());
	characterLink = line.GetAt(line.GetColumn() - 1);
	
	completeString = static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
	completeString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];

	cout << completeString << endl;

	memo.Write("글");
	line = memo.GetAt(memo.GetRow());
	characterLink = line.GetAt(line.GetColumn() - 1);

	completeString = static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
	completeString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];

	cout << completeString << endl;

	memo.Write('1');
	line = memo.GetAt(memo.GetRow());
	characterLink = line.GetAt(line.GetColumn() - 1);
	completeString = static_cast<SingleCharacter*>(characterLink)->GetValue();

	cout << completeString << endl;

	Long index = memo.Erase(memo.GetRow());
	cout << index << endl;

	Memo memo2;
	memo2 = memo;
	Character *characterLink2 = line.GetAt(line.GetColumn() - 1);
	string completeString2;
	completeString2 += static_cast<SingleCharacter*>(characterLink2)->GetValue();
	cout << completeString << endl;

	return 0;
}