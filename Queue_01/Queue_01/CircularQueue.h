#pragma once

#define TRUE 1
#define FALSE 0

#define QUEUE_LEN 50

typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUEUE_LEN];
} CQueue;

//연결 리스트 기반 큐

typedef struct _node
{
	Data data;
	_node* next;
} Node;

typedef struct _LQueue
{
	Node* front;
	Node* rear;
} LQueue;

typedef CQueue Queue;
//typedef LQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);


