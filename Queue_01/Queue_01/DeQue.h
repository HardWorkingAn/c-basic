#pragma once

#define TRUE 1
#define FALSE 0

#define QUEUE_LEN 50

typedef int Data;

typedef struct _Dnode
{
	Data data;
	_Dnode* next;
	_Dnode* pre;
} DNode;

typedef struct _dlDeque
{
	DNode* head;
	DNode* tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq);
int DQIsEmpty(Deque* pdeq);

void DQAddFirst(Deque* pdeq, Data data);
void DQAddLast(Deque* pdeq, Data data);

Data DQRemoveFirst(Deque* pdeq); // 덱 머리에서 데이터 삭제
Data DQRemoveLast(Deque* pdeq); // 덱 꼬리에서 데이터 삭제

Data DQGetFirst(Deque* pdeq);  // 덱 머리에서 데이터 참조
Data DQLastFirst(Deque* pdeq); // 덱 꼬리에서 데이터 참조