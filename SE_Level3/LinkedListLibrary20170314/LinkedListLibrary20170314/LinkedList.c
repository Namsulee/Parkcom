//LinkdedList.c
#include "LinkedList.h"
#include <memory.h>
#include <stdlib.h>

/*
함수명칭 : Create
기    능 : 연결리스트를 생성한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/19
*/
void Create(LinkedList *linkedList) {
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->length = 0;
	linkedList->current = NULL;
}

/*
함수명칭 : InsertBefore
기    능 : 연결리스트의 노드위치 앞에 노드를 끼워넣는다.
입    력 : 노드위치, 객체, 사이즈
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* InsertBefore(LinkedList *linkedList, Node *index, void *object, size_t size) {
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->next = index;
	if (linkedList->head != index) {
		linkedList->current->previous = index->previous;
		index->previous->next = linkedList->current;
	}
	else {
		linkedList->current->previous = linkedList->current;
		linkedList->head = linkedList->current;
	}
	index->previous = linkedList->current;
	linkedList->length++;
	return linkedList->current;
}

/*
함수명칭 : InsertAfter
기    능 : 연결리스트의 노드위치 뒤에 객체를 끼워넣는다.
입    력 : 노드위치, 객체, 사이즈
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* InsertAfter(LinkedList *linkedList, Node *index, void *object, size_t size) {
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->previous = index;
	if (linkedList->tail != index) {
		linkedList->current->next = index->next;
		index->next->previous = linkedList->current;
	}
	else {
		linkedList->current->next = linkedList->current;
		linkedList->tail = linkedList->current;
	}
	index->next = linkedList->current;
	linkedList->length++;
	return linkedList->current;
}

/*
함수명칭 : AppendFromHead
기    능 : 연결리스트의 헤드에 노드를 추가한다.
입    력 : 객체, 사이즈
출    력 : 객체위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* AppendFromHead(LinkedList *linkedList, void *object, size_t size) {
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->previous = linkedList->current;
	if (linkedList->head != NULL) {
		linkedList->current->next = linkedList->head;
		linkedList->head->previous = linkedList->current;
	}
	else {
		linkedList->current->next = linkedList->current;
		linkedList->tail = linkedList->current;
	}
	linkedList->head = linkedList->current;
	linkedList->length++;
	return linkedList->current;
}

/*
함수명칭 : AppendFromTail
기    능 : 연결리스트에 객체를 꼬리에 추가한다.
입    력 : 객체, 사이즈
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* AppendFromTail(LinkedList *linkedList, void *object, size_t size) {
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->next = linkedList->current;
	if (linkedList->tail != NULL) {
		linkedList->current->previous = linkedList->tail;
		linkedList->tail->next = linkedList->current;
	}
	else {
		linkedList->current->previous = linkedList->current;
		linkedList->head = linkedList->current;
	}
	linkedList->tail = linkedList->current;
	linkedList->length++;
	return linkedList->current;
}

/*
함수명칭 : Delete
기    능 : 연결리스트에서 노드위치의 노드를 삭제한다.
입    력 : 노드위치
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* Delete(LinkedList *linkedList, Node *index) {
	index->previous->next = index->next;
	index->next->previous = index->previous;
	linkedList->current = index->next;
	if (index == linkedList->head) {
		index->next->previous = index->next;
		linkedList->head = index->next;
	}
	if (index == linkedList->tail) {
		index->previous->next = index->previous;
		linkedList->tail = index->previous;
		linkedList->current = index->previous;
	}
	if (index == linkedList->head && index == linkedList->tail) {
		linkedList->head = NULL;
		linkedList->tail = NULL;
		linkedList->current = NULL;
	}
	if (index != NULL) {
		free(index);
		index = NULL;
	}
	linkedList->length--;
	return index;
}

/*
함수명칭 : DeleteFromHead
기    능 : 연결리스트에서 헤드위치의 노드를 삭제한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* DeleteFromHead(LinkedList *linkedList) {
	Node *index = linkedList->head;
	if (linkedList->head != linkedList->tail) {
		index->next->previous = index->next;
		linkedList->head = index->next;
		linkedList->current = index->next;
	}
	else {
		linkedList->head = NULL;
		linkedList->tail = NULL;
		linkedList->current = NULL;
	}
	if (index != NULL) {
		free(index);
		index = NULL;
	}
	linkedList->length--;
	return index;
}

/*
함수명칭 : DeleteFromTail
기    능 : 연결리스트의 꼬리노드를 삭제한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* DeleteFromTail(LinkedList *linkedList) {
	Node *index = linkedList->tail;
	if (linkedList->head != linkedList->tail) {
		index->previous->next = index->previous;
		linkedList->tail = index->previous;
		linkedList->current = index->previous;
	}
	else {
		linkedList->head = NULL;
		linkedList->tail = NULL;
		linkedList->current = NULL;
	}
	if (index != NULL) {
		free(index);
		index = NULL;
	}
	linkedList->length--;
	return index;
}

/*
함수명칭 : DeleteAllItems
기    능 : 연결리스트의 모든 노드를 삭제한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/19
*/
void DeleteAllItems(LinkedList *linkedList) {
	Node *previous = NULL;
	linkedList->current = linkedList->head;
	while (previous != linkedList->tail) {
		linkedList->head = linkedList->head->next;
		previous = linkedList->current;
		if (linkedList->current != NULL) {
			free(linkedList->current);
			linkedList->current = NULL;
		}
		linkedList->current = linkedList->head;
	}
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->current = NULL;
	linkedList->length = 0;
}

/*
함수명칭 : LinearSearchUnique
기    능 : 연결리스트에서 중복없는 키와 동일한 노드위치를 출력한다.
입    력 : 키, 비교함수
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* LinearSearchUnique(LinkedList *linkedList, void *key, int(*compare)(void *, void*)) {
	Node *index = NULL;
	Node *previous = NULL;
	linkedList->current = linkedList->head;
	while (previous != linkedList->tail && compare(linkedList->current + 1, key) != 0) {
		previous = linkedList->current;
		linkedList->current = linkedList->current->next;
	}
	if (previous != linkedList->tail) {
		index = linkedList->current;
	}
	return index;
}

/*
함수명칭 : LinearSearchDuplicate
기    능 : 연결리스트에서 키와 동일한 노드들을 찾아서 노드들과 개수를 출력한다.
입    력 : 키, 비교함수
출    력 : 노드위치들, 개수
작 성 자 : Joey
작성일자 : 2017/03/19
*/
void LinearSearchDuplicate(LinkedList *linkedList, void *key, Node* *(*indexes), ULong *count, int(*compare)(void *, void *)) {
	Node *previous = NULL;
	ULong i = 0;
	*count = 0;
	(*indexes) = (Node* (*))calloc(linkedList->length, sizeof(Node *));
	linkedList->current = linkedList->head;
	while (previous != linkedList->tail) 
		if (compare(linkedList->current + 1, key) == 0) {
			(*indexes)[i] = linkedList->current;
			(*count)++;
			i++;
		}
	previous = linkedList->current;
	linkedList->current = linkedList->current->next;
}

/*
함수명칭 : First
기    능 : 연결리스트의 헤드노드로 이동하고 현재 위치를 출력한다.
입    력 : 없음
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* First(LinkedList *linkedList) {
	linkedList->current = linkedList->head;
	return linkedList->current;
}

/*
함수명칭 : Previous
기    능 : 연결리스트의 현재노드의 이전노드로 이동하고 현재 위치를 출력한다.
입    력 : 없음
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* Previous(LinkedList *linkedList) {
	linkedList->current = linkedList->current->previous;
	return linkedList->current;
}

/*
함수명칭 : Next
기    능 : 연결리스트의 현재노드의 다음노드로 이동하고 현재 위치를 출력한다.
입    력 : 없음
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* Next(LinkedList *linkedList) {
	linkedList->current = linkedList->current->next;
	return linkedList->current;
}

/*
함수명칭 : Last
기    능 : 연결리스트의 꼬리노드로 이동하고 현재 위치를 출력한다.
입    력 : 없음
출    력 : 노드위치
작 성 자 : Joey
작성일자 : 2017/03/19
*/
Node* Last(LinkedList *linkedList) {
	linkedList->current = linkedList->tail;
	return linkedList->current;
}

/*
함수명칭 : Destroy
기    능 : 연결리스트를 제거한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/19
*/
void Destroy(LinkedList *linkedList) {
	Node *previous = NULL;
	linkedList->current = linkedList->head;
	while (previous != linkedList->tail) {
		linkedList->head = linkedList->head->next;
		previous = linkedList->current;
		if (linkedList->current != NULL) {
			free(linkedList->current);
			linkedList->current = NULL;
		}
		linkedList->current = linkedList->head;
	}
}

/*
함수명칭 : GetAt
기    능 : 연결리스트의 노드위치의 노드를 객체에 복사한다. 
입    력 : 노드위치, 객체, 사이즈
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/19
*/
void GetAt(LinkedList *linkedList, Node *index, void *object, size_t size) {
	memcpy(object, index + 1, size);
}