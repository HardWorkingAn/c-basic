#include "CircularQueue.h"
#include <iostream>

//���� ť
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
	if (pos == QUEUE_LEN - 1) //���� ��ġ�� �迭�� ������ ��ġ���
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
	if (NextPosIdx(pq->rear) == pq->front) //  rear�� return 0 ���� ����
	{
		printf_s("ť �޸� ����\n");
		exit(-1);
	}

 	pq->rear = NextPosIdx(pq->rear); // rear ��ĭ�̵� ���� rear�� 99�� �Ǿ����� return 0 �̶� rear�� 0�� �ȴ�.
	pq->queArr[pq->rear] = data;
}
Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf_s("ť �޸� ����\n");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}
Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf_s("ť �޸� ����\n");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

//���� ����Ʈ ��� ť
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
		pq->rear->next = newNode; // ������ ��带 newNode�� ����Ű���ϰ�
		pq->rear = newNode; // ���ο��带 rear�� �ٲ۴�.
	}
}
Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;
	if (QIsEmpty(pq))
	{
		printf_s("ť�� ����ֽ��ϴ�.");
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
		printf_s("ť�� ����ֽ��ϴ�.");
		exit(-1);
	}
	return pq->front->data;
}
*/