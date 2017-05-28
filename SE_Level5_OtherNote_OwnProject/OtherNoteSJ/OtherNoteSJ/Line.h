#pragma once
//Line.h
#ifndef _LINE_H
#define _LINE_H
#include "Composite.h"

typedef signed long int Long;
class Character;

class Line :public Composite{
public:
	Line(Long capacity = 256);
	Line(const Line& source);
	~Line();

	Long Write(char value);
	Long Write(char *value);
	Character* GetCharacter(Long index);
	Long Erase();

	Character* operator [] (Long index);
	Line& operator = (const Line& source);

	Long GetColumn() const;
private:
	Long column;
};

inline Long Line::GetColumn() const {
	return this->column;
}

#endif //_LINE_H