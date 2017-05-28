//Comoposite.cpp
#include "Composite.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
//#include "Memo.h"
#include "Line.h"

Composite::Composite(Long capacity) 
	:contents(capacity){
	this->capacity = capacity;
	this->length = 0;
}

Composite::Composite(const Composite& source) 
	:contents(source.capacity){

	Long i = 0;
	Contents *contents;
	Contents *newContents;

	while (i < source.length) {
		contents = const_cast<Composite&>(source).GetAt(i);
		if (dynamic_cast<Character*>(contents)) {
			if (dynamic_cast<SingleCharacter*>(contents)) {
				newContents = new SingleCharacter();
			}
			else {
				newContents = new DoubleCharacter();
			}
		}
		else {
			if (dynamic_cast<Line*>(contents)) {
				newContents = new Line();
			}
			/*else {
				newContents = new Memo();
			}*/
		}
		this->contents.Store(i, newContents);
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
		if (dynamic_cast<SingleCharacter*>(contentsLink)) {
			contentsLink = new SingleCharacter(*(static_cast<SingleCharacter*>(contentsLink)));
		}
		this->contents.Modify(i, contentsLink);
		i++;
	}
	return *this;
}

Contents* Composite::operator [] (Long index) {
	return this->contents[index];
}
