#pragma once
//SingleCharacter.h

#ifndef _SINGLECHARACTER_H
#define _SINGLECHARACTER_H

#include "Character.h"

class SingleCharacter : public Character {
public :
	SingleCharacter();
	SingleCharacter(char value);
	~SingleCharacter();
	
	bool IsEquals(const SingleCharacter& other);
	bool IsNotEquals(const SingleCharacter& other);	
	
	SingleCharacter& operator = (const SingleCharacter& source);
	bool operator == (const SingleCharacter& other);
	bool operator != (const SingleCharacter& other);
	Contents* Clone() const;

	char GetValue() const;
private:
	char value;
};

inline char SingleCharacter::GetValue() const {
	return this->value;
}

#endif _SINGLECHARACTER_H