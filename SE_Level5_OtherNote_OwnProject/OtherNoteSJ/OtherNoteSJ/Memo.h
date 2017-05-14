#pragma once
#ifndef _MEMO_H
#define _MEMO_H

#include "Array.h"
typedef signed long int Long;

class Character;
class Memo {
public:
	Memo(Long capacity = 100);
	Memo(const Memo& source);
	~Memo();
	Long Write(char value);
	Long Write(char* value);
	Character* GetAt(Long index);
	Long Erase(Long index);
	Memo& operator = (const Memo& source);
	Character* operator [] (Long index);
	Long GetCapacity() const;
	Long GetLength() const;
private:
	Array<Character*> characters;
	Long capacity;
	Long length;
};

inline Long Memo::GetCapacity() const {
	return this->capacity;
}

inline Long Memo::GetLength() const {
	return this->length;
}

#endif //_MEMO_H