//Main.c
/*
파일 명칭 : Main.c
기     능 : 연결리스트의 기능들을 수행한다.
작 성 자 : Joey
작성 일자 : 2017/03/19
*/

#include "LinkedList.h"
#include <stdio.h>

typedef signed long int Long;
int CompareIntegers(void *one, void *other);

int main(int argc, char *argv[]) {
	LinkedList linkedList;
	Long object;
	Node *index;

	//Creat
	Create(&linkedList);

	//AppendFormHead
	object = 300;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 1;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 10;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 4;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 2000;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 7;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	//Destroy
	Destroy(&linkedList);
	return 0;
}