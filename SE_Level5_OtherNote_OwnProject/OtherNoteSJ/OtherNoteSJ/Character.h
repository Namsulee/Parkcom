#pragma once
//Character.h
#ifndef _CHARACTER_H
#define _CHARACTER_H

class Character {
public:
	Character();
	Character(const Character& source);
	virtual ~Character() = 0;
	Character& operator = (const Character& source);

};

#endif //_CHARACTER_H