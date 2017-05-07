#pragma once
#ifndef _MEMO_H
#define _MEMO_H

#include "Array.h"
#include "SingleCharacter.h"

typedef signed long Long;

class Memo {
public:
	Memo(Long capacity = 100);
	Memo(const Memo& source);
	~Memo();
	Long Write(char value);
	SingleCharacter& GetAt(Long index);
	Memo& operator = (const Memo& source);
	SingleCharacter& operator [] (Long index);
	Long GetCapacity() const;
	Long GetLength() const;
private:
	Array<SingleCharacter> singleCharacters;
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