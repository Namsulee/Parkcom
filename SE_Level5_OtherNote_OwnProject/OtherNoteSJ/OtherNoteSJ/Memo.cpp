//Memo.cpp

#include "Memo.h"

Memo::Memo(Long capacity)
	:singleCharacters(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

Memo::Memo(const Memo& source)
	:singleCharacters(source.singleCharacters) {
	this->capacity = source.capacity;
	this->length = source.length;
}

Memo::~Memo() {

}

Long Memo::Write(char value) {
	Long index;
	if (this->length < this->capacity) {
		index = this->singleCharacters.Store(this->length, SingleCharacter(value));
	}
	else {
		index = this->singleCharacters.AppendFromRear(SingleCharacter(value));
		this->capacity++;
	}
	this->length++;
	return index;
}

SingleCharacter& Memo::GetAt(Long index) {
	return this->singleCharacters.GetAt(index);
}

Memo& Memo::operator = (const Memo& source) {
	this->singleCharacters = source.singleCharacters;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}
SingleCharacter& Memo::operator [] (Long index) {
	return this->singleCharacters.GetAt(index);
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