#pragma once
#include <string>

using namespace std;

#define  TRUE  1
#define  FALSE 0

//typedef int Data;
typedef string Data;

typedef struct _node
{
	int empno;
	Data data;
	_node* next;

} Node;

typedef struct _CircularLinkedList
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);
void LInsertFront(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);
