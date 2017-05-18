#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"

Line::Line(Long capacity)
	:characters(capacity) {
	this->length = 0;
	this->capacity = capacity;
	this->column = 0;
}

Line::Line(const Line& source)
	:characters(source.capacity) {
	Long i = 0;
	while (i < source.length) {
		if (dynamic_cast<SingleCharacter*>(const_cast<Line&>(source).characters.GetAt(i))) {
			this->characters[i] = new SingleCharacter(*(dynamic_cast<SingleCharacter*>(const_cast<Line&>(source).characters[i])));
		}
		else {
			this->characters[i] = new DoubleCharacter(*(dynamic_cast<DoubleCharacter*>(const_cast<Line&>(source).characters[i])));
		}
		i++;
	}
	this->capacity = source.capacity;
	this->length = source.length;
	this->column = source.column;
}

Line::~Line() {
	Long i = 0;
	while (i < this->length) {
		delete this->characters.GetAt(i);
		i++;
	}
}

Long Line::Write(char value) {
	SingleCharacter *singleCharacter = new SingleCharacter(value);
	Long index;
	if (this->length < this->capacity) {
		index = this->characters.Store(this->column, singleCharacter);
	}
	else {
		index = this->characters.AppendFromRear(singleCharacter);
		this->capacity++;
	}
	this->length++;
	this->column++;
	return index;
}

Long Line::Write(char *value) {
	DoubleCharacter *doubleCharacter = new DoubleCharacter(value);
	Long index;
	if (this->length < this->capacity) {
		index = this->characters.Store(this->column, doubleCharacter);
	}
	else {
		index = this->characters.AppendFromRear(doubleCharacter);
		this->capacity++;
	}
	this->length++;
	this->column++;
	return index;
}

Long Line::Erase(Long index) {
	Character *characterLink = this->characters.GetAt(index);
	if (index >= 0) {
		if (characterLink != 0) {
			delete characterLink;
		}
		index = this->characters.Delete(index);
		this->capacity--;
		this->length--;;
		this->column--;
	}
	return index;
}

Character* Line::GetAt(Long index) {
	return this->characters.GetAt(index);
}

Line& Line::operator=(const Line& source) {
	Long i = 0;
	Character *characterLink;
	while (i < this->length) {
		characterLink = this->characters.GetAt(i);
		if (characterLink != 0) {
			delete characterLink;
		}
		i++;
	}

	this->characters = source.characters;
	Character *temp;
	SingleCharacter *singleCharacter;
	DoubleCharacter *doubleCharacter;
	i = 0;
	while (i < source.length) {
		temp = const_cast<Line&>(source).characters.GetAt(i);
		if (dynamic_cast<SingleCharacter*>(temp)) {
			singleCharacter = new SingleCharacter(*(static_cast<SingleCharacter*>(temp)));
			this->characters.Modify(i, singleCharacter);
		}
		else {
			doubleCharacter = new DoubleCharacter(*(static_cast<DoubleCharacter*>(temp)));
			this->characters.Modify(i, doubleCharacter);
		}
		i++;
	}
	this->capacity = source.capacity;
	this->length = source.length;
	this->column = source.column;
	return *this;
}

Character* Line::operator[](Long index) {
	return this->characters.GetAt(index);
}