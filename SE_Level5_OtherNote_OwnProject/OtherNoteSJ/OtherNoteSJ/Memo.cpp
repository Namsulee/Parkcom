//Memo.cpp
#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"

Memo::Memo(Long capacity)
	:characters(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Memo::Memo(const Memo& source)
	:characters(source.characters) {
	this->capacity = source.capacity;
	this->length = source.length;
}

Memo::~Memo() {
	Long i = 0;
	while (i < this->length) {
		delete this->characters.GetAt(i);
		i++;
	}
}

Long Memo::Write(char value) {
	Long index;
	SingleCharacter *singleCharacter = new SingleCharacter(value);
	if (this->length < this->capacity) {
		index = this->characters.Store(this->length, singleCharacter);
	}
	else {
		index = this->characters.AppendFromRear(singleCharacter);
		this->capacity++;
	}
	this->length++;
	return index;
}

Long Memo::Write(char* value) {
	Long index;
	DoubleCharacter *doubleCharacter = new DoubleCharacter(value);
	if (this->length < this->capacity) {
		index = this->characters.Store(this->length, doubleCharacter);
	}
	else {
		index = this->characters.AppendFromRear(doubleCharacter);
		this->capacity++;
	}
	this->length++;
	return index;
}

Character* Memo::GetAt(Long index) {
	return this->characters.GetAt(index);
}

Memo& Memo::operator = (const Memo& source) {
	this->characters = source.characters;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}
Character* Memo::operator [] (Long index) {
	return this->characters.GetAt(index);
}

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

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	Memo memo;
	Character *characterLink;
	Long index;
	string characters;

	index = memo.Write("วั");
	characterLink = memo.GetAt(index);
	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];

	index = memo.Write("ฑÛ");
	characterLink = memo.GetAt(index);
	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
	characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];

	cout << characters << endl;

	return 0;
}