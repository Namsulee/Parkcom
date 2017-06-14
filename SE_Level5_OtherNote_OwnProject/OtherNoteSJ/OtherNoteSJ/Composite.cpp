//Comoposite.cpp
#include "Composite.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include "Memo.h"
#include "Line.h"

Composite::Composite(Long capacity) 
	:contents(capacity){
	this->capacity = capacity;
	this->length = 0;
}

Composite::Composite(const Composite& source) 
	:contents(source.capacity){

	Long i = 0;
	Contents *contentsLink;
	Contents *newContentsLink;

	while (i < source.length) {
		contentsLink = const_cast<Composite&>(source).GetAt(i);
		if (dynamic_cast<Character*>(contentsLink)) {
			if (dynamic_cast<SingleCharacter*>(contentsLink)) {
				newContentsLink = new SingleCharacter(*(static_cast<SingleCharacter*>(contentsLink)));
			}
			else {
				newContentsLink = new DoubleCharacter(*(static_cast<DoubleCharacter*>(contentsLink)));
			}
		}
		else {
			if (dynamic_cast<Line*>(contentsLink)) {
				newContentsLink = new Line(*(static_cast<Line*>(contentsLink)));
			}
			else {
				newContentsLink = new Memo(*(static_cast<Memo*>(contentsLink)));
			}
		}
		this->contents.Store(i, newContentsLink);
		i++;
	}

	this->capacity = source.capacity;
	this->length = source.length;
}

Composite::~Composite() {
	Long i = 0;
	while (i < this->length) {
		if (this->contents[i] != 0) {
			delete this->contents[i];
		}		
		i++;
	}
}

Long Composite::Add(Contents *contentsLink) {
	Long index;
	if (this->length < this->capacity) {
		index = this->contents.Store(this->length, contentsLink);
	}
	else {
		index = this->contents.AppendFromRear(contentsLink);
		this->capacity++;
	}
	this->length++;
	return index;
}

Contents* Composite::GetAt(Long index) {
	return this->contents.GetAt(index);
}

Long Composite::Remove(Long index) {
	if (this->contents[index] != 0) {
		delete this->contents[index];
	}
	index = this->contents.Delete(index);
	this->capacity--;
	this->length--;
	return index;
}

Composite& Composite::operator = (const Composite& source) {
	Long i = 0;
	while (i < this->length) {
		if (this->contents[i] != 0) {
			delete this->contents[i];
		}		
		i++;
	}
	this->contents = source.contents;
	Contents *contentsLink;
	i = 0;
	while (i < source.length) {
		contentsLink = const_cast<Composite&>(source).contents[i];

		if (dynamic_cast<Character*>(contentsLink)) {
			if (dynamic_cast<SingleCharacter*>(contentsLink)) {
				contentsLink = new SingleCharacter(*(static_cast<SingleCharacter*>(contentsLink)));
			}
			else {
				contentsLink = new DoubleCharacter(*(static_cast<DoubleCharacter*>(contentsLink)));
			}
		}
		else {
			if (dynamic_cast<Line*>(contentsLink)) {
				contentsLink = new Line(*(static_cast<Line*>(contentsLink)));
			}
			else {
				contentsLink = new Memo(*(static_cast<Memo*>(contentsLink)));
			}
		}
		this->contents.Modify(i, contentsLink);
		i++;
	}
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}

Contents* Composite::operator [] (Long index) {
	return this->contents[index];
}
