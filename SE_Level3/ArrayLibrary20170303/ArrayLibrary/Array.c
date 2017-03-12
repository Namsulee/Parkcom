//Array.c
/*
함수 명칭 : Array.c
기    능 : 배열라이브러리 기능을 제공한다.
작 성 자 : Joey
작성일자 : 2017/03/06
*/

#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//함수 선언
int CompareIntegers(void *ont, void *other);

// 원장님 main 샘플 코드
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
함수 명칭 : main
기    능 : 정수형 배열 라이브러리 기능을 확인한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/11
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

	//배열을 생성한다.
	Create(&array, 5, sizeof(Long));
	Create(&one, 5, sizeof(Long));
	Create(&other, 5, sizeof(Long));

	//배열에 값을 저장한다.
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

	//배열을 끼워넣는다.
	object = 7;
	index = Insert(&array, 2, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//배열을 고친다.
	object = 8;
	index = Modify(&array, 2, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//배열을 삭제한다.
	index = Delete(&array, 2, sizeof(Long));
	if (index == -1) {
		printf("지웠습니다.\n");
	}

	//배열 1에 데이터를 저장한다.
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

	//배열 2에 데이터를 저장한다.
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
		printf("처음 위치의 객체를 지웠습니다.\n");
	}

	//AppendFromRear
	object = 999;
	index = AppendFromRear(&array, &object, sizeof(Long));
	GetAt(&array, index, &ret, sizeof(Long));
	printf("%d\n", ret);

	//DeleteFromRear
	index = DeleteFromRear(&array, sizeof(Long));
	if (index == -1) {
		printf("마지막 위치의 객체를 지웠습니다.\n");
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
		printf("찾을 수 없습니다.\n");
	}

	key = 999;
	index = LinearSearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("찾을 수 없습니다.\n");
	}

	//BinarySearchUnique
	key = 300;
	index = BinarySearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("찾을 수 없습니다.\n");
	}

	key = 990;
	index = BinarySearchUnique(&array, &key, sizeof(Long), CompareIntegers);
	if (index >= 0) {
		GetAt(&array, index, &ret, sizeof(Long));
		printf("%d\n", ret);
	}
	else {
		printf("찾을 수 없습니다.\n");
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
함수 명칭 : Create
기    능 : 배열을 준비한다.
입    력 : 크기, 사이즈
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/06
*/
void Create(Array*array, Long capacity, size_t size) {
	array->front = calloc(capacity, size);
	array->capacity = capacity;
	array->length = 0;
}

/*
함수 명칭 : Store
기    능 : 배열에 객체를 저장한다.
입    력 : 위치, 객체, 사이즈
출    력 : 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
*/
Long Store(Array *array, Long index, void *object, size_t size) {
	memcpy(((char*)(array->front)) + (index * size), object, size);
	array->length++;

	return index;
}

/*
함수 명칭 : Insert
기    능 : 배열 위치에 객체를 추가한다.
입    력 : 위치, 객체, 사이즈
출    력 : 저장된 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : AppendFromFront
기    능 : 배열의 맨 앞에 객체를 추가한다.
입    력 : 객체, 사이즈
출    력 : 저장된 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : AppendFromRear
기    능 : 배열 맨뒤에 객체를 추가한다.
입    력 : 객체, 사이즈
출    력 : 추가된 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : Delete
기    능 : 배열의 객체를 삭제한다.
입    력 : 위치, 사이즈
출    력 : 위치(-1)
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : DeleteFromFront
기    능 : 맨앞의 객체를 삭제한다.
입    력 : 사이즈
출    력 : 삭제위치(-1)
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : DeleteFromRear
기    능 : 마지막의 객체를 삭제한다.
입    력 : 사이즈
출    력 : 삭제한 위치(-1)
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : Clear
기    능 : 배열을 해제한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : Modify
기    능 : 입력받은 객체를 배열 위치의 객체를 고친다.
입    력 : 위치, 객체, 사이즈
출    력 : 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
*/
Long Modify(Array *array, Long index, void *object, size_t size) {
	memcpy(((char*)(array->front)) + (index*size), object, size);
	return index;
}

/*
함수 명칭 : LinearSearchUnique
기    능 : key와 동일한 객체를 찾아서 위치를 반환한다.
입    력 : key, 사이즈, 비교함수
출    력 : 객체 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : LinearSearchDuplicate
기    능 : 배열에서 주어진 키값과 동일한 객체를 찾는다.
입    력 : 키, 사이즈, 비교 함수
출    력 : 객체들, 개수
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : BinarySearchUnique
기    능 : 주어진 키와 같은 객체를 이분검색을 통해서 찾는다.
입    력 : 키, 사이즈, 비교함수
출    력 : 객체의 위치
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : BinarySearchDuplicate
기    능 : 주어진 키와 같은 객체들을 이분검색을 통해서 찾는다.
입    력 : 키, 사이즈, 비교함수
출    력 : 위치들, 개수
작 성 자 : Joey
작성 일자 : 2017/03/06
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
함수 명칭 : SelectionSort
기    능 : 배열을 선택정렬로 오름차순으로 정렬한다.
입    력 : 사이즈, 비교함수
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/08
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
함수 명칭 : BubbleSort
기    능 : 배열을 버블정렬을 이용해서 오름차순으로 정렬한다.
입    력 : 사이즈, 비교함수
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/08
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
함수 명칭 : InsertionSort
기    능 : 배열을 삽입정렬을 이용해서 오름차순으로 정렬한다.
입    력 : 사이즈, 비교함수
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/11
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
함수 명칭 : MergeSort
기    능 : 2개의 배열을 입력받아서 오름차순으로 정렬한다.
입    력 : 배열1, 배열2, 사이즈, 비교함수
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/11
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
함수 명칭 : Destroy
기    능 : Array를 해제한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/06
*/
void Destroy(Array *array) {
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
}

/*
함수 명칭 : GetAt
기    능 : 배열의 위치의 객체를 객체에 복사한다.
입    력 : 위치, 객체, 사이즈
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/06
*/
void GetAt(Array *array, Long index, void *object, size_t size) {
	memcpy(object, ((char*)(array->front)) + (index * size), size);
}

/*
함수 명칭 : CompareIntegers
기    능 : 정수와 정수를 비교해서 대소 비교 결과를 반환한다.
입    력 : 정수, 정수
출    력 : 대소 비교 결과
작 성 자 : Joey
작성 일자 : 2017/03/06
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