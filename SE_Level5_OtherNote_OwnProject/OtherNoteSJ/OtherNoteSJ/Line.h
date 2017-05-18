#pragma once
#ifndef _LINE_H
#define _LINE_H

#include "Array.h"
typedef signed long int Long;
class Character;
class Line {
public:
	Line(Long capacity = 100);
	Line(const Line& source);
	~Line();
	Long Write(char value);
	Long Write(char *value);
	Long Erase(Long index);
	Character* GetAt(Long index);
	Character* operator[](Long index);
	Line& operator=(const Line& source);	
	Long GetCapacity() const;
	Long GetLength() const;
	Long GetColumn() const;
private:
	Array<Character*> characters;
	Long capacity;
	Long length;
	Long column;
};

inline Long Line::GetCapacity() const {
	return this->capacity;
}

inline Long Line::GetLength() const {
	return this->length;
}

inline Long Line::GetColumn() const {
	return this->column;
}
#endif _LINE_H