//Memo.cpp
#include "Memo.h"
#include "Line.h"

Memo::Memo(Long capacity)
	:Composite(capacity) {
	this->row = Composite::Add(new Line);
}

Memo::Memo(const Memo& source)
	: Composite(source) {
	this->row = source.row;
}

Memo::~Memo() {

}

Long Memo::AddLine() {
	this->row = Composite::Add(new Line);
	return this->row;
}

Line* Memo::GetLine(Long index) {
	return static_cast<Line*>(Composite::GetAt(index));
}

Long Memo::RemoveLine(Long index) {
	index = Composite::Remove(index);
	this->row--;
	return index;
}

Line* Memo::operator [](Long index) {
	return static_cast<Line*>(Composite::operator[](index));
}

Memo& Memo::operator = (const Memo& source) {
	Composite::operator = (source);
	this->row = source.row;
	return *this;
}