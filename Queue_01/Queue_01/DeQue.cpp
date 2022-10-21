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
		pdeq->tail = newNode; // 디큐에 아무것도 없을경우
	}
	else
	{
		//앞으로 추가되기 때문에 1 2  3순으로 넣으면 3 2 1 으로 들어간다
		pdeq->head->pre = newNode; // 한개라도 존재할 경우 현재 head의 node 앞에 생긴 newnode에 연결 ( ->으로 읽을 경우    pre <- node -> next )
	}
	newNode->pre = nullptr; 
	pdeq->head = newNode;  // 이후 해드 위치 변경
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
	DNode* rnode = pdeq->head;  //미리 해드가 참조하는 node 참조
	Data rdata;
	if (DQIsEmpty(pdeq))
	{
		printf_s(" 메모리 오류 \n");
		exit(-1);
	}

	rdata = pdeq->head->data;
	pdeq->head = pdeq->head->next; // 미리 선언한 rnode가 앞에있는 노드를 참조하기 때문에 해드는 다음 node 참조

	delete rnode;

	if (pdeq->head == nullptr)
		pdeq->tail = nullptr; // 마지막 한개 남은 node를 지울경우 tail도 참조할게 안남기 때문에 nullptr 설정
	else
		pdeq->head->pre = nullptr; // 해드의 pre는 현재 지워진 rnode를 참조하기 때문에 nullptr로 참조제거
	
	return rdata;

}
Data DQRemoveLast(Deque* pdeq)
{
	DNode* rnode = pdeq->tail;
	Data rdata;
	if (DQIsEmpty(pdeq))
	{
		printf_s(" 메모리 오류 \n");
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
		printf_s(" 메모리 오류 \n");
		exit(-1);
	}
	return pdeq->head->data;
}
Data DQLastFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf_s(" 메모리 오류 \n");
		exit(-1);
	}
	return pdeq->tail->data;
}