#pragma once
#include "Point.h"

#define TRUE 1
#define FALSE 0

//typedef int LData;
typedef Point* LData; //문제 04-3, 문제 04-4

typedef struct _node
{
	LData   data;
	_node*  next;
}node;

typedef struct _linkedList
{
	node* head;
	node* cur;
	node* before;
	int numOfData;
	int (*comp)(LData d1, LData d2);

} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);



void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

