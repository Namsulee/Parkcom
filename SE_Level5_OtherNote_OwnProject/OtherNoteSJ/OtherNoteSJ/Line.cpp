//Line.cpp
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"

Line::Line(Long capacity) 
	:Composite(capacity) {
	this->column = 0;
}
Line::Line(const Line& source)
	:Composite(source) {
	this->column = source.column;
}

Line::~Line() {

}

Long Line::Write(char value) {
	SingleCharacter *singleCharacter = new SingleCharacter(value);
	Long index = Composite::Add(singleCharacter);
	this->column++;
	return index;
}

Long Line::Write(char *value) {
	DoubleCharacter *doubleCharacter = new DoubleCharacter(value);
	Long index = Composite::Add(doubleCharacter);
	this->column++;
	return index;
}

Character* Line::GetCharacter(Long index) {
	return static_cast<Character*>(Composite::GetAt(index));
}

Long Line::Erase() {
	Long index = Composite::Remove(--this->column);
	return index;
}


Character* Line::operator [] (Long index) {
	return static_cast<Character*>(Composite::operator[](index));
}

Line& Line::operator = (const Line& source) {
	Composite::operator=(source);
	this->column = source.column;
	return *this;
}

Contents* Line::Clone() const {
	return new Line(*this);
}