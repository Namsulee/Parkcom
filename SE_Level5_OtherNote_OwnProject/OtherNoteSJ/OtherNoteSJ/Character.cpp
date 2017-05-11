//Character.cpp
#include "Character.h"
#include "SingleCharacter.h"

Character::Character() {

}

Character::Character(const Character& source) {
	//에러발생
	//if (dynamic_cast<SingleCharacter*>(source)) {
	//	this->value = source.value;
	//}
	//else {
	//	this->value[0] = source.value[0];
	//	this->value[1] = source.value[1];
	//}
}

Character::~Character() {

}

Character& Character::operator=(const Character& source) {
	//에러발생
	//if (dynamic_cast<SingleCharacter*>(source)) {
	//	this->value = source.value;
	//}
	//else {
	//	this->value[0] = source.value[0];
	//	this->value[1] = source.value[1];
	//}
	return *this;
}
