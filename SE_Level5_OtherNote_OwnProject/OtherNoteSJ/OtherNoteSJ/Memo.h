#pragma once
#ifndef _MEMO_H
#define _MEMO_H

#include "Array.h"
#include "Line.h"
typedef signed long int Long;

class Memo {
public:
	Memo(Long capacity = 100);
	Memo(const Memo& source);
	~Memo();
	void Write(char value);
	void Write(char* value);
	Line& GetAt(Long index);
	Long Erase(Long index);
	Memo& operator = (const Memo& source);
	Line& operator [] (Long index);
	Long GetCapacity() const;
	Long GetLength() const;
	Long GetRow() const;
private:
	Array<Line> lines;
	Long capacity;
	Long length;
	Long row;
};

inline Long Memo::GetCapacity() const {
	return this->capacity;
}

inline Long Memo::GetLength() const {
	return this->length;
}

inline Long Memo::GetRow() const {
	return this->row;
}

#endif //_MEMO_H