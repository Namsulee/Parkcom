#pragma once
//Memo.h

#ifndef _MEMO_H
#define _MEMO_H
#include "Composite.h"
typedef signed long int Long;
class Line;

class Memo :public Composite {
public:
	Memo(Long capacity = 250);
	Memo(const Memo& source);
	~Memo();

	Long AddLine();
	Line* GetLine(Long index);
	Long RemoveLine(Long index);

	Line* operator [](Long index);
	Memo& operator = (const Memo& source);

	Long GetRow() const;
private:
	Long row;
};

inline Long Memo::GetRow() const {
	return this->row;
}

#endif //_MEHO_H