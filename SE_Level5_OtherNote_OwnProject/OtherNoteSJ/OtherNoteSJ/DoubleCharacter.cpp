//DoubleCharacter.cpp
#include "DoubleCharacter.h"

DoubleCharacter::DoubleCharacter() {
	this->value[0] = ' ';
	this->value[1] = ' ';
}

DoubleCharacter::DoubleCharacter(char* value) {
	this->value[0] = value[0];
	this->value[1] = value[1];
}

DoubleCharacter::DoubleCharacter(const DoubleCharacter& source) {
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];
}

DoubleCharacter::~DoubleCharacter() {}

bool DoubleCharacter::IsEqual(const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] == other.value[0] && this->value[1] == other.value[2]) {
		ret = true;
	}
	return ret;
}

bool DoubleCharacter::IsNotEquals(const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] != other.value[0] || this->value[1] != other.value[2]) {
		ret = true;
	}
	return ret;
}

bool DoubleCharacter::operator == (const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] == other.value[0] && this->value[1] == other.value[2]) {
		ret = true;
	}
	return ret;
}

bool DoubleCharacter::operator != (const DoubleCharacter& other) {
	bool ret = false;
	if (this->value[0] != other.value[0] || this->value[1] != other.value[2]) {
		ret = true;
	}
	return ret;
}

DoubleCharacter& DoubleCharacter::operator = (const DoubleCharacter& source) {
	this->value[0] = source.value[0];
	this->value[1] = source.value[1];
	return *this;
}