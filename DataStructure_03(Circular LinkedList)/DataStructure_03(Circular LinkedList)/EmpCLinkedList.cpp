#include "EmpCLinkedList.h"
#include <string.h>

void ListInit(List* plist)
{
	plist->cur = nullptr;
	plist->before = nullptr;
	plist->numOfData = 0;
	plist->tail = nullptr;
}
void LInsertFront(List* plist, Data data)
{
	Node* newNode = new Node();
	newNode->data = data;

	if (plist->tail == nullptr)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next; // 먼저 tail에 저장된 포인터를 먼저 newNode의 next에 연결해주고 
		plist->tail->next = newNode; // 이후 tail가 NewNode 를 저장한다.
	}
	(plist->numOfData)++;
}
void LInsert(List* plist, Data data)
{
	Node* newNode = new Node();
	newNode->data = data;

	if (plist->tail == nullptr)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{

		newNode->next = plist->tail->next; // 먼저 tail에 저장된 포인터를 먼저 newNode의 next에 연결해주고 
		plist->tail->next = newNode; // 이후 tail가 NewNode 를 저장한다.
		plist->tail = newNode; // tail을 새로 추가된 node로 하여 Linsert는 새로 추가된 node을 꼬리로 유지시켜준다.
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == nullptr)
	{
		return FALSE;
	}
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Data* pdata)
{
	if (plist->tail == nullptr)
	{
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
Data LRemove(List* plist)
{
	//삭제 하기 위한 임시 객체생성
	Node* rpos = plist->cur;
	Data data = rpos->data;
	

	// 삭제하려는게 tail경우
	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next) // 자료가 한개 저장되있을경우
		{
			plist->tail = nullptr;
		}
		else
		{
			plist->tail = plist->before; // next를 통해 before 값과 cur 값을 가지기 때문에 문제 없음
		}
	}

	//삭제를 위한 커서이동
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	//삭제
	delete rpos;
	(plist->numOfData)--;
	return data;
}
int LCount(List* plist)
{
	return plist->numOfData;
}