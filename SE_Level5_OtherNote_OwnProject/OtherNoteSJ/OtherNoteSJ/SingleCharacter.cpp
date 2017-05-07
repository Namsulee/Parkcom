#include "SingleCharacter.h"

//디폴트 생성자
SingleCharacter::SingleCharacter() {
	this->value = ' ';
}

//매개변수에 의한 생성자
SingleCharacter::SingleCharacter(char value) {
	this->value = value;
}

//복사생성자
SingleCharacter::SingleCharacter(const SingleCharacter& source) {
	this->value = source.value;
}

//소멸자
SingleCharacter::~SingleCharacter() {

}

//관계연산
bool SingleCharacter::IsEqual(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

//관계연산
bool SingleCharacter::IsNotEquals(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return ret;
}

//==연산자 오버로딩
bool SingleCharacter::operator==(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

//!=연산자 오버로딩
bool SingleCharacter::operator!=(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return ret;
}

//치환연산자
SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	this->value = source.value;
	return *this;
}