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

Data DQRemoveFirst(Deque* pdeq); // �� �Ӹ����� ������ ����
Data DQRemoveLast(Deque* pdeq); // �� �������� ������ ����

Data DQGetFirst(Deque* pdeq);  // �� �Ӹ����� ������ ����
Data DQLastFirst(Deque* pdeq); // �� �������� ������ ����