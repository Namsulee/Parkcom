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

	//1. �޸� �ѱ��ڸ� ���´�.
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

	index = lineLink->Write("��");
	characterLink = lineLink->GetCharacter(index);
	if (dynamic_cast<SingleCharacter*>(characterLink)) {
		coutString += static_cast<SingleCharacter*>(characterLink)->GetValue();
	}
	else {
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[0];
		coutString += static_cast<DoubleCharacter*>(characterLink)->GetValue()[1];
	}

	index = lineLink->Write("��");
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
	
	//2. �޸� �ѱ��ڸ� �����.
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