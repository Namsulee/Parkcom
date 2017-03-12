//Array.c
/*
�Լ� ��Ī : Array.c
��    �� : �迭���̺귯�� ����� �����Ѵ�.
�� �� �� : Joey
�ۼ����� : 2017/03/06
*/

#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//�Լ� ����
int CompareIntegers(void *ont, void *other);

// ����� main ���� �ڵ�
//int main(int argc, char*argv[]){
//	Array array;
//	int object; 
//	int ret;
//	Long index;
//	int key;
//
//	Crate(&array, 3, sizeof(int));
//
//	object = 100;
//	index = Store(&array, 0, &object, sizeof(int));
//	GetAt(&array, index, &ret, sizeof(int));
//	printf("%d\n", ret);
//
//	key = 100;
//	index = LinearSearchUnique(&array, &key, sizeof(int), CompareIntegers);
//	GetAt(&array, index, &ret, sizeof(int));
//	printf("%d\n", ret);
//
//	Destroy(&array);
//
//	return 0;
//}

/*
�Լ� ��Ī : main
��    �� : ������ �迭 ���̺귯�� ����� Ȯ���Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/11
*/
int main(int argc, char* argv[]) {
	Array array;
	Long index;
	Long(*indexes);
	Long count;
	Long object;
	Long ret;
	Array one;
	Array other;
	Long key;
	Long i;

	//�迭�� �����Ѵ�.
	Create(&array, 5, sizeof(Long));
	Create(&one, 5, sizeof(Long));
	Create(&other, 5, sizeof(Long));

	//�迭�� ���� �����Ѵ�.
	object = 4000;
	index = Store(&array, 0, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 20;
	index = Store(&array, 1, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 50000;
	index = Store(&array, 2, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 1;
	index = Store(&array, 3, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 300;
	index = Store(&array, 4, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//�迭�� �����ִ´�.
	object = 7;
	index = Insert(&array, 2, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//�迭�� ��ģ��.
	object = 8;
	index = Modify(&array, 2, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//�迭�� �����Ѵ�.
	index = Delete(&array, 2, sizeof(Long));
	if (index == -1) {
		printf("�������ϴ�.\n");
	}

	//�迭 1�� �����͸� �����Ѵ�.
	object = 4000;
	index = Store(&one, 0, &object, sizeof(Long));
	GetAt(&one, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 20;
	index = Store(&one, 1, &object, sizeof(Long));
	GetAt(&one, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 50000;
	index = Store(&one, 2, &object, sizeof(Long));
	GetAt(&one, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 1;
	index = Store(&one, 3, &object, sizeof(Long));
	GetAt(&one, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 300;
	index = Store(&one, 4, &object, sizeof(Long));
	GetAt(&one, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//�迭 2�� �����͸� �����Ѵ�.
	object = 4000;
	index = Store(&other, 0, &object, sizeof(Long));
	GetAt(&other, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 20;
	index = Store(&other, 1, &object, sizeof(Long));
	GetAt(&other, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 50000;
	index = Store(&other, 2, &object, sizeof(Long));
	GetAt(&other, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 1;
	index = Store(&other, 3, &object, sizeof(Long));
	GetAt(&other, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	object = 300;
	index = Store(&other, 4, &object, sizeof(Long));
	GetAt(&other, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//AppendFromFront
	object = 999;
	index = AppendFromFront(&array, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//DeleteFromFront
	index = DeleteFromFront(&array, sizeof(Long));
	if (index == -1) {
		printf("ó�� ��ġ�� ��ü�� �������ϴ�.\n");
	}

	//AppendFromRear
	object = 999;
	index = AppendFromRear(&array, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//DeleteFromRear
	index = DeleteFromRear(&array, sizeof(Long));
	if (index == -1) {
		printf("������ ��ġ�� ��ü�� �������ϴ�.\n");
	}

	//SelectionSort
	SelectionSort(&array, sizeof(Long), CompareIntegers);
	i = 0; 
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");

	//BubbleSort
	BubbleSort(&one, sizeof(Long), CompareIntegers);
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");

	//InsertionSort
	InsertionSort(&other, sizeof(Long), CompareIntegers);
	i = 0;
	while (i < other.length) {
		GetAt(&other, i, &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");

	//LinearSearchUnique
	key = 300;
	index = LinearSearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("ã�� �� �����ϴ�.\n");
	}

	key = 999;
	index = LinearSearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("ã�� �� �����ϴ�.\n");
	}

	//BinarySearchUnique
	key = 300;
	index = BinarySearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("ã�� �� �����ϴ�.\n");
	}

	key = 990;
	index = BinarySearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("ã�� �� �����ϴ�.\n");
	}

	//Clear
	Clear(&array);
	if (array.front == NULL) {
		printf("%d, %d\n", array.capacity, array.length);
	}

	//MergeSort
	MergeSort(&array, &one, &other, sizeof(Long), CompareIntegers);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");

	//LinearSearchDuplicate
	key = 20;
	LinearSearchDuplicate(&array, &key, &indexes, &count, sizeof(Long), CompareIntegers);
	i = 0;
	while (i < count) {
		GetAt(&array, indexes[i], &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");

	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//BinarySearchDuplicate
	key = 1;
	BinarySearchDuplicate(&array, &key, &indexes, &count, sizeof(Long), CompareIntegers);
	i = 0;
	while (i < count) {
		GetAt(&array, indexes[i], &ret, sizeof(Long));
		printf("%d ", ret);
		i++;
	}
	printf("\n");

	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//Destroy
	Destroy(&one);
	Destroy(&other);
	Destroy(&array);

	return 0;
}

/*
�Լ� ��Ī : Create
��    �� : �迭�� �غ��Ѵ�.
��    �� : ũ��, ������
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
void Create(Array*array, Long capacity, size_t size) {
	array->front = calloc(capacity, size);
	array->capacity = capacity;
	array->length = 0;
}

/*
�Լ� ��Ī : Store
��    �� : �迭�� ��ü�� �����Ѵ�.
��    �� : ��ġ, ��ü, ������
��    �� : ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long Store(Array *array, Long index, void *object, size_t size) {
	memcpy(((char*)(array->front)) + (index * size), object, size);
	array->length++;

	return index;
}

/*
�Լ� ��Ī : Insert
��    �� : �迭 ��ġ�� ��ü�� �߰��Ѵ�.
��    �� : ��ġ, ��ü, ������
��    �� : ����� ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long Insert(Array *array, Long index, void *object, size_t size) {
	void(*temp);
	Long i = 0;
	temp = calloc(array->capacity + 1, size);
	while (i < index) {
		memcpy(((char*)temp) + (i * size), ((char*)(array->front)) + (i * size), size);
		i++;
	}
	while (i < array->length) {
		memcpy(((char*)temp) + ((i + 1) * size), ((char*)(array->front)) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		//array->front = NULL;
	}
	array->front = temp;
	array->capacity++;
	memcpy(((char*)(array->front)) + (index * size), object, size);
	array->length++;

	return index;
}

/*
�Լ� ��Ī : AppendFromFront
��    �� : �迭�� �� �տ� ��ü�� �߰��Ѵ�.
��    �� : ��ü, ������
��    �� : ����� ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long AppendFromFront(Array *array, void *object, size_t size) {
	void(*temp);
	Long index = 0;
	Long i = 0;

	temp = calloc(array->length + 1, size);
	while (i < array->length) {
		memcpy(((char*)temp) + ((i + 1) * size), ((char*)(array->front)) + (i*size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		//array->front = NULL;
	}
	array->front = temp;
	array->capacity++;
	memcpy(((char*)(array->front)) + (index *size), object, size);
	array->length++;

	return index;
}

/*
�Լ� ��Ī : AppendFromRear
��    �� : �迭 �ǵڿ� ��ü�� �߰��Ѵ�.
��    �� : ��ü, ������
��    �� : �߰��� ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long AppendFromRear(Array *array, void *object, size_t size) {
	void(*temp);
	Long i = 0;
	Long index;

	temp = calloc(array->length + 1, size);
	while (i < array->length) {
		memcpy(((char*)temp) + ((i) * size), ((char*)(array->front)) + (i*size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		//array->front = NULL;
	}
	array->front = temp;
	array->capacity++;
	index = array->capacity - 1;
	memcpy(((char*)(array->front)) + (index *size), object, size);
	array->length++;

	return index;
}

/*
�Լ� ��Ī : Delete
��    �� : �迭�� ��ü�� �����Ѵ�.
��    �� : ��ġ, ������
��    �� : ��ġ(-1)
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long Delete(Array *array, Long index, size_t size) {
	void(*temp) = NULL;
	Long i = 0;
	Long j = 0;

	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
	}

	while (i < index) {
		memcpy(((char*)temp) + (j*size), ((char*)(array->front)) + (i * size), size);
		j++;
		i++;
	}
	i = index + 1;
	while (i < array->length) {
		memcpy(((char*)temp) + (j*size), ((char*)(array->front)) + (i * size), size);
		j++;
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	if (array->capacity > 1) {
		array->front = temp;
	}
	array->length--;
	array->capacity--;;
	index = -1;

	return index;
}

/*
�Լ� ��Ī : DeleteFromFront
��    �� : �Ǿ��� ��ü�� �����Ѵ�.
��    �� : ������
��    �� : ������ġ(-1)
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long DeleteFromFront(Array *array, size_t size) {
	void(*temp) = NULL;
	Long index;
	Long i = 1;
	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
	}
	while (i < array->length) {
		memcpy(((char*)temp) + ((i - 1) *size), ((char*)(array->front)) + (i* size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	if (array->capacity > 1){
		array->front = temp;
	}
	array->length--;
	array->capacity--;
	index = -1;
	return index;
}

/*
�Լ� ��Ī : DeleteFromRear
��    �� : �������� ��ü�� �����Ѵ�.
��    �� : ������
��    �� : ������ ��ġ(-1)
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long DeleteFromRear(Array *array, size_t size) {
	void(*temp) = NULL;
	Long index;
	Long i = 0;
	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
	}
	while (i < array->length - 1) {
		memcpy(((char*)temp) + (i * size), ((char*)(array->front)) + (i* size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	if (array->capacity > 1){
		array->front = temp;
	}
	array->length--;
	array->capacity--;
	index = -1;
	return index;
}

/*
�Լ� ��Ī : Clear
��    �� : �迭�� �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
void Clear(Array *array) {
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	array->capacity = 0;
	array->length = 0;
}

/*
�Լ� ��Ī : Modify
��    �� : �Է¹��� ��ü�� �迭 ��ġ�� ��ü�� ��ģ��.
��    �� : ��ġ, ��ü, ������
��    �� : ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long Modify(Array *array, Long index, void *object, size_t size) {
	memcpy(((char*)(array->front)) + (index*size), object, size);
	return index;
}

/*
�Լ� ��Ī : LinearSearchUnique
��    �� : key�� ������ ��ü�� ã�Ƽ� ��ġ�� ��ȯ�Ѵ�.
��    �� : key, ������, ���Լ�
��    �� : ��ü ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long LinearSearchUnique(Array *array, void *key, size_t size, int(*compare)(void*, void*)) {
	Long index = -1;
	Long i = 0;

	while (i < array->length && compare(((char*)(array->front)) + (i * size), key) != 0) {
		i++;
	}
	if (i < array->length) {
		index = i;
	}
	return index;
}

/*
�Լ� ��Ī : LinearSearchDuplicate
��    �� : �迭���� �־��� Ű���� ������ ��ü�� ã�´�.
��    �� : Ű, ������, �� �Լ�
��    �� : ��ü��, ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
void LinearSearchDuplicate(Array *array, void *key, Long *(*indexes), Long *count, size_t size, int(*compare)(void*, void*)){
	Long i = 0;
	Long index = 0;
	*count = 0;
	*indexes = (Long(*))calloc(array->length, sizeof(Long));
	while (i < array->length) {
		if (compare(((char*)(array->front)) + (i *size), key) == 0) {
			(*indexes)[index] = i;
			index++;
			(*count)++;
		}
		i++;
	}
}

/*
�Լ� ��Ī : BinarySearchUnique
��    �� : �־��� Ű�� ���� ��ü�� �̺а˻��� ���ؼ� ã�´�.
��    �� : Ű, ������, ���Լ�
��    �� : ��ü�� ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
Long BinarySearchUnique(Array *array, void *key, size_t size, int(*compare)(void*, void*)){
	Long index = - 1;
	Long begin = 0;
	Long end;
	Long middle;
	
	end = array->length - 1;
	middle = (begin + end) / 2;
	while (begin <= end && compare(((char*)(array->front)) + (middle * size), key) != 0) {
		if (compare(((char*)(array->front)) + (middle * size), key) > 0) {
			begin = middle + 1;
		}
		else {
			end = middle - 1;
		}
		middle = (begin + end) / 2;
	}
	if (begin <= end) {
		index = middle;
	}
	return index;
}

/*
�Լ� ��Ī : BinarySearchDuplicate
��    �� : �־��� Ű�� ���� ��ü���� �̺а˻��� ���ؼ� ã�´�.
��    �� : Ű, ������, ���Լ�
��    �� : ��ġ��, ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
void BinarySearchDuplicate(Array *array, void *key, Long *(*indexes), Long *count, size_t size, int(*compare)(void*, void*)){
	Long begin = 0;
	Long end;
	Long middle;
	Long keyBegin;
	Long keyEnd;
	Long i;
	Long j = 0;
	Long index;
	*count = 0;
	*indexes = NULL;

	end = array->length - 1;
	middle = (begin + end) / 2;
	while (begin <= end && compare(((char*)(array->front)) + (middle * size), key) != 0) {
		if (compare(((char*)(array->front)) + (middle * size), key) < 0) {
			begin = middle + 1;
		}
		else {
			end = middle - 1;
		}
		middle = (begin + end) / 2;
	}

	index = middle;
	i = index - 1;
	while (i >= begin && compare(((char*)(array->front)) + (i *size), key) == 0) {
		i--;
	}
	keyBegin = i + 1;
	i = keyBegin;
	while (i <= end && compare(((char*)(array->front)) + (i * size), key) == 0) {
		(*count)++;
		i++;
	}
	keyEnd = i - 1;
	if (*count > 0) {
		*indexes = (Long(*))calloc(*count, sizeof(Long));
	}
	i = keyBegin;
	while (i <= keyBegin && compare(((char*)(array->front)) + (i*size), key) == 0) {
		(*indexes)[j] = i;
		j++;
		i++;
	}
}

/*
�Լ� ��Ī : SelectionSort
��    �� : �迭�� �������ķ� ������������ �����Ѵ�.
��    �� : ������, ���Լ�
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/08
*/
void SelectionSort(Array *array, size_t size, int(*compare)(void*, void*)) {
	Long i = 0;
	Long j;
	void *temp;
	temp = malloc(size);
	while (i < array->length - 1){
		j = i + 1;
		while (j < array->length) {
			if (compare(((char*)(array->front)) + (i *size), ((char*)(array->front)) + (j *size)) > 0) {
				memcpy(temp, ((char*)(array->front)) + (j*size), size);
				memcpy(((char*)(array->front)) + (j * size), ((char*)(array->front)) + (i * size), size);
				memcpy(((char*)(array->front)) + (i * size), temp, size);
			}
			j++;
		}
		i++;
	}
	if (temp != NULL) {
		free(temp);
		temp = NULL;
	}
}

/*
�Լ� ��Ī : BubbleSort
��    �� : �迭�� ���������� �̿��ؼ� ������������ �����Ѵ�.
��    �� : ������, ���Լ�
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/08
*/
void BubbleSort(Array *array, size_t size, int(*compare)(void*, void*)) {
	void *temp;
	Long i = 0;
	Long j;

	temp = malloc(size);
	while (i < array->length - 1) {
		j = 0;
		while (j < array->length - i - 1) {
			if (compare(((char*)(array->front)) + (j * size), ((char*)(array->front)) + ((j + 1) * size)) > 0) {
				memcpy(temp, ((char*)(array->front)) + (j  *size), size);
				memcpy(((char*)(array->front)) + (j * size), ((char*)(array->front)) + ((j + 1) * size), size);
				memcpy(((char*)(array->front)) + ((j + 1) * size), temp, size);
			}
			j++;
		}
		i++;
	}
	if (temp != NULL) {
		free(temp);
		temp = NULL;
	}
}

/*
�Լ� ��Ī : InsertionSort
��    �� : �迭�� ���������� �̿��ؼ� ������������ �����Ѵ�.
��    �� : ������, ���Լ�
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/11
*/
void InsertionSort(Array *array, size_t size, int(*compare)(void*, void*)) {
	void *temp;
	Long i = 1;
	Long j = 0;
	Long k;

	temp = malloc(size);
	while (i < array->length) {
		memcpy(temp, ((char*)(array->front)) + (i * size), size);
		j = i - 1;
		while (j >= 0 && compare( ((char*)(array->front)) + (i *size), ((char*)(array->front)) + (j * size) ) < 0){
			j--;
		}
		k = i;
		j++;
		while (k > j) {
			memcpy(((char*)(array->front)) + (k * size), ((char*)(array->front)) + ((k - 1) * size), size);
			k--;
		}
		memcpy(((char*)(array->front)) + (j * size), temp, size);
		i++;
	}
	if (temp != NULL) {
		free(temp);
		temp = NULL;
	}
}

/*
�Լ� ��Ī : MergeSort
��    �� : 2���� �迭�� �Է¹޾Ƽ� ������������ �����Ѵ�.
��    �� : �迭1, �迭2, ������, ���Լ�
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/11
*/
void MergeSort(Array *array, Array *one, Array *other, size_t size, int(*compare)(void*, void*)){
	Long i = 0;
	Long j = 0;
	Long k = 0;

	if (array->front != NULL){
		free(array->front);
	}
	array->front = calloc(one->length + other->length, size);
	array->capacity = one->length + other->length;
	while (i < one->length && j < other->length) {
		if (compare(((char*)(one->front)) + (i * size), ((char*)(other->front)) + (j * size)) < 0) {
			memcpy(((char*)(array->front)) + (k * size), ((char*)(one->front)) + (i * size), size);
			i++;
		}
		else {
			memcpy(((char*)(array->front)) + (k * size), ((char*)(other->front)) + (j * size), size);
			j++;
		}
		k++;
	}
	while (i < one->length) {
		memcpy(((char*)(array->front)) + (k * size), ((char*)(one->front)) + (i * size), size);
		k++;
		i++;
	}
	while (j < other->length) {
		memcpy(((char*)(array->front)) + (k * size), ((char*)(other->front)) + (j * size), size);
		k++;
		j++;
	}
	array->length = one->length + other->length;
}

/*
�Լ� ��Ī : Destroy
��    �� : Array�� �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
void Destroy(Array *array) {
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
}

/*
�Լ� ��Ī : GetAt
��    �� : �迭�� ��ġ�� ��ü�� ��ü�� �����Ѵ�.
��    �� : ��ġ, ��ü, ������
��    �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
void GetAt(Array *array, Long index, void *object, size_t size) {
	memcpy(object, ((char*)(array->front)) + (index * size), size);
}

/*
�Լ� ��Ī : CompareIntegers
��    �� : ������ ������ ���ؼ� ��� �� ����� ��ȯ�Ѵ�.
��    �� : ����, ����
��    �� : ��� �� ���
�� �� �� : Joey
�ۼ� ���� : 2017/03/06
*/
int CompareIntegers(void *one, void*other) {
	int ret;

	if (*((int*)one) > *((int*)other)) {
		ret = 1;
	}
	else if (*((int*)one) == *((int*)other)) {
		ret = 0;
	}
	else if (*((int*)one) < *((int*)other)) {
		ret = -1;
	}
	return ret;
}