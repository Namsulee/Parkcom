//Memo.cpp
#include "Memo.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"

Memo::Memo(Long capacity)
	:lines(capacity) {
	this->capacity = capacity;
	this->length = 0;
	this->row = 0;
}

Memo::Memo(const Memo& source)
	:lines(source.lines) {
	this->capacity = source.capacity;
	this->length = source.length;
	this->row = source.row;
}

Memo::~Memo() {
	
}

void Memo::Write(char value) {
	Line *lineLink = &this->lines.GetAt(this->row);
	Long index = lineLink->Write(value);
}

void Memo::Write(char* value) {
	Line *lineLink = &this->lines.GetAt(this->row);
	Long index = lineLink->Write(value);
}

Line& Memo::GetAt(Long index) {
	return this->lines.GetAt(index);
}

Long Memo::Erase(Long index) {
	Line *lineLink = &this->lines.GetAt(index);
	if (lineLink->GetLength() >= 2) {
		index = lineLink->Erase(index);
	}
	else if (lineLink->GetLength() == 1) {
		index = lineLink->Erase(index);
		if (this->length >= 2) {
			this->lines.Delete(this->row);
			this->capacity--;
			this->length--;
			this->row--;
		}
	}
	return index;
}

Memo& Memo::operator = (const Memo& source) {
	
	if (&this->lines != 0) {
		delete[] & this->lines;
	}
	this->lines = source.lines;
	Long i = 0;
	while (i < source.length) {
		this->lines[i] = const_cast<Memo&>(source).lines[i];
		i++;
	}
	return *this;
}
Line& Memo::operator [] (Long index) {
	return this->lines.GetAt(index);
}
