//SingleCharacter.cpp
#include "SingleCharacter.h"

SingleCharacter::SingleCharacter() 
	:Character(){
	this->value = ' ';
}

SingleCharacter::SingleCharacter(char value) 
	:Character(){
	this->value = value;
}

SingleCharacter::~SingleCharacter() {

}

bool SingleCharacter::IsEquals(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

bool SingleCharacter::IsNotEquals(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return false;
}

SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	Character::operator=(source);
	this->value = source.value;
	return *this;
}

bool SingleCharacter::operator==(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

bool SingleCharacter::operator!=(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return false;
}

Contents* SingleCharacter::Clone() const {
	return new SingleCharacter(*this);
}