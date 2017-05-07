#include "SingleCharacter.h"

//����Ʈ ������
SingleCharacter::SingleCharacter() {
	this->value = ' ';
}

//�Ű������� ���� ������
SingleCharacter::SingleCharacter(char value) {
	this->value = value;
}

//���������
SingleCharacter::SingleCharacter(const SingleCharacter& source) {
	this->value = source.value;
}

//�Ҹ���
SingleCharacter::~SingleCharacter() {

}

//���迬��
bool SingleCharacter::IsEqual(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

//���迬��
bool SingleCharacter::IsNotEquals(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return ret;
}

//==������ �����ε�
bool SingleCharacter::operator==(const SingleCharacter& other) {
	bool ret = false;
	if (this->value == other.value) {
		ret = true;
	}
	return ret;
}

//!=������ �����ε�
bool SingleCharacter::operator!=(const SingleCharacter& other) {
	bool ret = false;
	if (this->value != other.value) {
		ret = true;
	}
	return ret;
}

//ġȯ������
SingleCharacter& SingleCharacter::operator=(const SingleCharacter& source) {
	this->value = source.value;
	return *this;
}