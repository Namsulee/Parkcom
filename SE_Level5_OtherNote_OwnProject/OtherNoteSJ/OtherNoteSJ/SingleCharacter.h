#pragma once
#ifndef _SINGLECHARACTER_H
#define _SINGLECHARATER_H

class SingleCharacter {
public:
	SingleCharacter();
	SingleCharacter(char value);
	SingleCharacter(const SingleCharacter& source);
	~SingleCharacter();	
	bool IsEqual(const SingleCharacter& other);
	bool IsNotEquals(const SingleCharacter& other);
	bool operator == (const SingleCharacter& other);
	bool operator != (const SingleCharacter& other);
	SingleCharacter& operator = (const SingleCharacter& source);

	char GetValue() const;
protected:
	char value;
};

inline char SingleCharacter::GetValue() const {
	return this->value;
}

#endif //_SINGLECHARATER_H
