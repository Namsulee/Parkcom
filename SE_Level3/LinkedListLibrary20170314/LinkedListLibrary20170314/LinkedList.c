//LinkdedList.c
#include "LinkedList.h"
#include <memory.h>
#include <stdlib.h>

/*
�Լ���Ī : Create
��    �� : ���Ḯ��Ʈ�� �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
*/
void Create(LinkedList *linkedList) {
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->length = 0;
	linkedList->current = NULL;
}

/*
�Լ���Ī : InsertBefore
��    �� : ���Ḯ��Ʈ�� �����ġ �տ� ��带 �����ִ´�.
��    �� : �����ġ, ��ü, ������
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : InsertAfter
��    �� : ���Ḯ��Ʈ�� �����ġ �ڿ� ��ü�� �����ִ´�.
��    �� : �����ġ, ��ü, ������
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : AppendFromHead
��    �� : ���Ḯ��Ʈ�� ��忡 ��带 �߰��Ѵ�.
��    �� : ��ü, ������
��    �� : ��ü��ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : AppendFromTail
��    �� : ���Ḯ��Ʈ�� ��ü�� ������ �߰��Ѵ�.
��    �� : ��ü, ������
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : Delete
��    �� : ���Ḯ��Ʈ���� �����ġ�� ��带 �����Ѵ�.
��    �� : �����ġ
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : DeleteFromHead
��    �� : ���Ḯ��Ʈ���� �����ġ�� ��带 �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : DeleteFromTail
��    �� : ���Ḯ��Ʈ�� ������带 �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : DeleteAllItems
��    �� : ���Ḯ��Ʈ�� ��� ��带 �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : LinearSearchUnique
��    �� : ���Ḯ��Ʈ���� �ߺ����� Ű�� ������ �����ġ�� ����Ѵ�.
��    �� : Ű, ���Լ�
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : LinearSearchDuplicate
��    �� : ���Ḯ��Ʈ���� Ű�� ������ ������ ã�Ƽ� ����� ������ ����Ѵ�.
��    �� : Ű, ���Լ�
��    �� : �����ġ��, ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : First
��    �� : ���Ḯ��Ʈ�� ������ �̵��ϰ� ���� ��ġ�� ����Ѵ�.
��    �� : ����
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
*/
Node* First(LinkedList *linkedList) {
	linkedList->current = linkedList->head;
	return linkedList->current;
}

/*
�Լ���Ī : Previous
��    �� : ���Ḯ��Ʈ�� �������� �������� �̵��ϰ� ���� ��ġ�� ����Ѵ�.
��    �� : ����
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
*/
Node* Previous(LinkedList *linkedList) {
	linkedList->current = linkedList->current->previous;
	return linkedList->current;
}

/*
�Լ���Ī : Next
��    �� : ���Ḯ��Ʈ�� �������� �������� �̵��ϰ� ���� ��ġ�� ����Ѵ�.
��    �� : ����
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
*/
Node* Next(LinkedList *linkedList) {
	linkedList->current = linkedList->current->next;
	return linkedList->current;
}

/*
�Լ���Ī : Last
��    �� : ���Ḯ��Ʈ�� �������� �̵��ϰ� ���� ��ġ�� ����Ѵ�.
��    �� : ����
��    �� : �����ġ
�� �� �� : Joey
�ۼ����� : 2017/03/19
*/
Node* Last(LinkedList *linkedList) {
	linkedList->current = linkedList->tail;
	return linkedList->current;
}

/*
�Լ���Ī : Destroy
��    �� : ���Ḯ��Ʈ�� �����Ѵ�.
��    �� : ����
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
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
�Լ���Ī : GetAt
��    �� : ���Ḯ��Ʈ�� �����ġ�� ��带 ��ü�� �����Ѵ�. 
��    �� : �����ġ, ��ü, ������
��    �� : ����
�� �� �� : Joey
�ۼ����� : 2017/03/19
*/
void GetAt(LinkedList *linkedList, Node *index, void *object, size_t size) {
	memcpy(object, index + 1, size);
}