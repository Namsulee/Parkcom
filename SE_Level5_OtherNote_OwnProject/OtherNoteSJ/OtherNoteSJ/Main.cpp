//Main.cpp
#include "Memo.h"
#include "Line.h"
#include "Character.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <iostream>
#include <string>

using namespace std;

typedef signed long int Long;

int main(int argc, char *argv[]) {
	
	Memo memo;

	//1. 메모에 한글자를 적는다.
	Character *characterLink;
	string coutString;
	
	Line *lineLink = memo.GetLine(0);
	Long index = lineLink->Write('a');
	characterLink = lineLink->GetCharacter(index);
	if (dynamic_cast<SingleCharacter*>(characterLink)) {
		coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
	}
	else {
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
	}

	index = lineLink->Write("한");
	characterLink = lineLink->GetCharacter(index);
	if (dynamic_cast<SingleCharacter*>(characterLink)) {
		coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
	}
	else {
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
	}

	index = lineLink->Write("글");
	characterLink = lineLink->GetCharacter(index);
	if (dynamic_cast<SingleCharacter*>(characterLink)) {
		coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
	}
	else {
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
	}
	
	index = lineLink->Write('b');
	characterLink = lineLink->GetCharacter(index);
	if (dynamic_cast<SingleCharacter*>(characterLink)) {
		coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
	}
	else {
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
	}

	cout << "Write character : " << coutString << endl;
	
	//2. 메모에 한글자를 지운다.
	index = lineLink->Erase();
	Long i = 0;
	coutString = "";
	while (i < lineLink->GetLength()) {
		characterLink = lineLink->GetCharacter(i);
		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
		}
		else {
			coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
			coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
		}
		i++;
	}
	cout << "Erase Character : " << coutString << endl;

	index = lineLink->Erase();
	i = 0;
	coutString = "";
	while (i < lineLink->GetLength()) {
		characterLink = lineLink->GetCharacter(i);
		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
		}
		else {
			coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
			coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
		}
		i++;
	}
	cout << "Erase Character : " << coutString << endl;

	//3. AddLine
	coutString = "";
	index = memo.AddLine();
	lineLink = memo.GetLine(index);
	index = lineLink->Write('d');
	characterLink = lineLink->GetCharacter(index);
	if (dynamic_cast<SingleCharacter*>(characterLink)) {
		coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
	}
	else {
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
	}
	cout << "AddLine : " << coutString << endl;

	//4. RemoveLine
	cout << memo.GetLength() << endl;
	index = memo.RemoveLine(1);
	cout << memo.GetLength() << endl;

	return 0;
}