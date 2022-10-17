#pragma once
#include <string>

using namespace std;

#define  TRUE  1
#define  FALSE 0
// 양 방향 연결리스트

typedef int Data;

typedef struct _Dnode
{
	Data data;
	_Dnode* next; // 다음 주소
	_Dnode* pre; // 이전 주소
} DNode;

typedef struct _DoublyLinkedList
{
	DNode* head;
	DNode* tail;
	DNode* cur;
	int numOfData;
} DList;

typedef DList List;

void DListInit(List* plist);
void DInsert(List* plist, Data data);
void DInsertFront(List* plist, Data data);

int DFirst(List* plist, Data* pdata);
int DNext(List* plist, Data* pdata);
int DPrevious(List* plist, Data* pdata);
Data DRemove(List* plist);
int DCount(List* plist);