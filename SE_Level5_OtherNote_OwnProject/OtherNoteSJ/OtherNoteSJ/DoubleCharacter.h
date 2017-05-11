#pragma once
//DoubleCharacter.h
#ifndef _DOUBLECHARACTER_H
#define _DOUBLECHARACTER_H
#include "Character.h"

class DoubleCharacter : public Character {
public:
	DoubleCharacter();
	DoubleCharacter(char* value);
	DoubleCharacter(const DoubleCharacter& source);
	~DoubleCharacter();
	bool IsEqual(const DoubleCharacter& other);
	bool IsNotEquals(const DoubleCharacter& other);
	bool operator == (const DoubleCharacter& other);
	bool operator != (const DoubleCharacter& other);
	DoubleCharacter& operator = (const DoubleCharacter& source);
	char* GetValue() const;
private:
	char value[2];
};

inline char* DoubleCharacter::GetValue() const {
	return const_cast<char*>(this->value);
}

#endif _DOUBLECHARACTER_H
