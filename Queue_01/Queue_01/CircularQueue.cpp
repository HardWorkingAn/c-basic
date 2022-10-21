#include "CircularQueue.h"
#include <iostream>

//기존 큐
void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}
int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == QUEUE_LEN - 1) //현재 위치가 배열의 마지막 위치라면
	{
		return 0;
	}
	else
	{
		return pos + 1;
	}
}

void Enqueue(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front) //  rear가 return 0 으로 인해
	{
		printf_s("큐 메모리 오류\n");
		exit(-1);
	}

 	pq->rear = NextPosIdx(pq->rear); // rear 한칸이동 만약 rear가 99가 되었으면 return 0 이라 rear는 0이 된다.
	pq->queArr[pq->rear] = data;
}
Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf_s("큐 메모리 오류\n");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}
Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf_s("큐 메모리 오류\n");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

//연결 리스트 기반 큐
/*
void QueueInit(Queue* pq)
{
	pq->front = nullptr;
	pq->rear = nullptr;
}
int QIsEmpty(Queue* pq)
{
	if (pq->front == nullptr)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = new Node;
	newNode->next = nullptr;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode; // 마지막 노드를 newNode로 가르키게하고
		pq->rear = newNode; // 새로운노드를 rear로 바꾼다.
	}
}
Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;
	if (QIsEmpty(pq))
	{
		printf_s("큐가 비어있습니다.");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	delete delNode;
	return retData;

}
Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf_s("큐가 비어있습니다.");
		exit(-1);
	}
	return pq->front->data;
}
*/