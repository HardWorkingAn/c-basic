#include "DeQue.h"
#include <iostream>

void DequeInit(Deque* pdeq)
{
	pdeq->head = nullptr;
	pdeq->tail = nullptr;
}
int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == nullptr)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
	DNode* newNode = new DNode;
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
	{
		pdeq->tail = newNode; // ��ť�� �ƹ��͵� �������
	}
	else
	{
		//������ �߰��Ǳ� ������ 1 2  3������ ������ 3 2 1 ���� ����
		pdeq->head->pre = newNode; // �Ѱ��� ������ ��� ���� head�� node �տ� ���� newnode�� ���� ( ->���� ���� ���    pre <- node -> next )
	}
	newNode->pre = nullptr; 
	pdeq->head = newNode;  // ���� �ص� ��ġ ����
}
void DQAddLast(Deque* pdeq, Data data)
{
	DNode* newNode = new DNode;
	newNode->data = data;

	newNode->pre = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode; 
	else
		pdeq->tail->next = newNode; 

	newNode->next = nullptr;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	DNode* rnode = pdeq->head;  //�̸� �ص尡 �����ϴ� node ����
	Data rdata;
	if (DQIsEmpty(pdeq))
	{
		printf_s(" �޸� ���� \n");
		exit(-1);
	}

	rdata = pdeq->head->data;
	pdeq->head = pdeq->head->next; // �̸� ������ rnode�� �տ��ִ� ��带 �����ϱ� ������ �ص�� ���� node ����

	delete rnode;

	if (pdeq->head == nullptr)
		pdeq->tail = nullptr; // ������ �Ѱ� ���� node�� ������ tail�� �����Ұ� �ȳ��� ������ nullptr ����
	else
		pdeq->head->pre = nullptr; // �ص��� pre�� ���� ������ rnode�� �����ϱ� ������ nullptr�� ��������
	
	return rdata;

}
Data DQRemoveLast(Deque* pdeq)
{
	DNode* rnode = pdeq->tail;
	Data rdata;
	if (DQIsEmpty(pdeq))
	{
		printf_s(" �޸� ���� \n");
		exit(-1);
	}

	rdata = pdeq->tail->data;
	pdeq->tail = pdeq->tail->pre;

	delete rnode;

	if (pdeq->tail == nullptr)
		pdeq->head = nullptr;
	else
		pdeq->tail->next = nullptr;

	return rdata;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf_s(" �޸� ���� \n");
		exit(-1);
	}
	return pdeq->head->data;
}
Data DQLastFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf_s(" �޸� ���� \n");
		exit(-1);
	}
	return pdeq->tail->data;
}