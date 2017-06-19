//DoubleCharacter.cpp

#include "DoubleCharacter.h"

DoubleCharacter::DoubleCharacter()
	:Character() {
	this->value[0] = ' ';
	this->value[1] = ' ';
}
DoubleCharacter::DoubleCharacter(char *value) 
	:Character() {
	this->value[0] = value[0];
	this->value[1] = value[1];
}
DoubleCharacter::~DoubleCharacter() {
	
}

bool DoubleCharacter::IsEquals(const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] == other.value[0] && this->value[1] == other.value[1]) {
		ret = true;
	}
	return ret;
}
bool DoubleCharacter::IsNotEquls(const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] != other.value[0] || this->value[1] != other.value[1]) {
		ret = true;
	}
	return ret;
}

DoubleCharacter& DoubleCharacter::operator=(const DoubleCharacter& source) {
	Character::operator=(source);
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];
	return *this;
}
bool DoubleCharacter::operator == (const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] == other.value[0] && this->value[1] == other.value[1]) {
		ret = true;
	}
	return ret;
}
bool DoubleCharacter::operator != (const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] != other.value[0] || this->value[1] != other.value[1]) {
		ret = true;
	}
	return ret;
}

Contents* DoubleCharacter::Clone() const {
	return new DoubleCharacter(*this);
}