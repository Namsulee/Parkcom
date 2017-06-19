#pragma once
//DoubleCharacter.h

#ifndef _DOUBLECHARACTER_H
#define _DOUBLECHARACTER_H

#include "Character.h"

class DoubleCharacter : public Character{
public:
	DoubleCharacter();
	DoubleCharacter(char *value);
	~DoubleCharacter();

	bool IsEquals(const DoubleCharacter& other);
	bool IsNotEquls(const DoubleCharacter& other);
	
	DoubleCharacter& operator=(const DoubleCharacter& source);
	bool operator == (const DoubleCharacter& other);
	bool operator != (const DoubleCharacter& other);

	Contents* Clone() const;

	char* GetValue() const;
private:
	char value[2];
};

inline char* DoubleCharacter::GetValue() const{
	return const_cast<char*>(this->value);
}

#endif _DOUBLECHARACTER_H
