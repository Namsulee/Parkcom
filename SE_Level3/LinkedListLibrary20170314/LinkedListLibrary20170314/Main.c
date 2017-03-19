//Main.c
/*
���� ��Ī : Main.c
��     �� : ���Ḯ��Ʈ�� ��ɵ��� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/19
*/

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef signed long int Long;
int CompareIntegers(void *one, void *other);

int main(int argc, char *argv[]) {
	LinkedList linkedList;
	Long object;
	Node *index;
	Long key;
	Node* (*indexes);
	Long count;
	Long i;

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

	//Previous, First & Previous
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);
	index = First(&linkedList);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	//Next, Last & Next
	index = Next(&linkedList);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);
	index = Last(&linkedList);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);
	index = Next(&linkedList);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	//Delete
	index = Delete(&linkedList, index);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}
	index = DeleteFromHead(&linkedList);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}
	index = DeleteFromTail(&linkedList);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}
	DeleteAllItems(&linkedList);

	//LinearSearchUnique
	object = 100;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 300;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	object = 500;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	key = 300;
	index = LinearSearchUnique(&linkedList, &key, CompareIntegers);
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	//LinearSearchDuplicate
	object = 300;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &object, sizeof(Long));
	printf("%d\n", object);

	key = 300;
	LinearSearchDuplicate(&linkedList, &key, &indexes, &count, CompareIntegers);
	i = 0;
	while (i < count) {
		GetAt(&linkedList, indexes[i], &object, sizeof(Long));
		printf("%d ", object);
		i++;
	}
	printf("\n");
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}	

	//Destroy
	Destroy(&linkedList);
	return 0;
}

int CompareIntegers(void *one, void *other) {
	int ret;
	if (*((Long*)one) > *((Long*)other)) {
		ret = 1;
	}
	else if (*((Long*)one) == *((Long*)other)) {
		ret = 0;
	}
	else if (*((Long*)one) < *((Long*)other)) {
		ret = -1;
	}
	return ret;
}
