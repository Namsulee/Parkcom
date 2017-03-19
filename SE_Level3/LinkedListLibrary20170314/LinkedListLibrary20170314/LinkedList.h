#pragma once
//LinkedList.h
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stddef.h>

//사용자 정의 자료형
typedef unsigned long int ULong;

typedef struct _node Node;	//전방선언
typedef struct _node {
	Node *previous;
	Node *next;
}Node;

typedef struct _linkedList {
	Node *head;
	Node *tail;
	ULong length;
	Node *current;
}LinkedList;

//함수 선언들
void Create(LinkedList *linkedList);
Node* InsertBefore(LinkedList *linkedList, Node *index, void *object, size_t size);
Node* InsertAfter(LinkedList *linkedList, Node *index, void *object, size_t size);
Node* AppendFromHead(LinkedList *linkedList, void *object, size_t size);
Node* AppendFromTail(LinkedList *linkedList, void *object, size_t size);
Node* Delete(LinkedList *linkedList, Node *index);
Node* DeleteFromHead(LinkedList *linkedList);
Node* DeleteFromTail(LinkedList *linkedList);
void DeleteAllItems(LinkedList *linkedList);
Node* LinearSearchUnique(LinkedList *linkedList, void *key, int(*compare)(void *, void*));
void LinearSearchDuplicate(LinkedList *linkedList, void *key, Node* *(*indexes), ULong *count, int (*compare)(void *, void *));
Node* First(LinkedList *linkedList);
Node* Previous(LinkedList *linkedList);
Node* Next(LinkedList *linkedList);
Node* Last(LinkedList *linkedList);
void Destroy(LinkedList *linkedList);
void GetAt(LinkedList *linkedList, Node* index,void *object, size_t size);
#endif //_LINKEDLIST_H