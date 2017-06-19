#pragma once
//Contents.h
#ifndef _CONTENTS_H
#define _CONTENTS_H

typedef signed long int Long;
class Contents {

public :
	Contents();
	Contents(const Contents& source);
	virtual ~Contents() = 0;

	virtual Long Add(Contents *contens) { return -1; };
	virtual Contents* GetAt(Long index) { return 0; };
	virtual Long Remove(Long index) { return -1; };

	Contents* operator [] (Long index) { return 0; };//�����ڴ� virtual�� ���� �ʴ´�. �������̵� ���Ѵ�
	Contents& operator = (const Contents& source);

	virtual Contents* Clone() const = 0;
	
};

#endif //_CONTENTS_H