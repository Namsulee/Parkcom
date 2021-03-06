#pragma once
//Composite.h
#ifndef _COMPOSITE_H
#define _COMPOSITE_H
#include "Contents.h"
#include "Array.h"

typedef signed long int Long;

class Composite : public Contents{
public:
	Composite(Long capacity);
	Composite(const Composite& source);
	virtual ~Composite() = 0;

	virtual Long Add(Contents *contentsLink);
	virtual Contents* GetAt(Long index);
	virtual Long Remove(Long index);

	Contents* operator [] (Long index);
	Composite& operator = (const Composite& source);
	
	Long GetCapacity() const;
	Long GetLength() const;
private:
	Array<Contents*> contents;
	Long capacity;
	Long length;
};

inline Long Composite::GetCapacity() const {
	return this->capacity;
}

inline Long Composite::GetLength() const {
	return this->length;
}

#endif //_COMPOSITE_H