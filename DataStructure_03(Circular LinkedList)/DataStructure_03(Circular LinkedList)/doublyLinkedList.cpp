#include "doublyLinkedList.h"
using namespace std;

void DListInit(List* plist)
{
	/*
	plist->head = nullptr;
	plist->numOfData = 0;
	*/
	// 05 - 2 ����
	DNode* dumy = new DNode();
	plist->head = dumy;
	DNode* NewNode = new DNode();
	plist->tail = NewNode;

	plist->head->pre = nullptr;
	plist->head->next = plist->tail;

	plist->tail->next = nullptr;
	plist->tail->pre = plist->head;

	plist->numOfData = 0;
}
void DInsert(List* plist, Data data)
{
	/*
	DNode* newNode = new DNode();
	newNode->data = data;
	
	//ó�� next�� head�� ������ ���� nullptr�� ���Եȴ�.
	newNode->next = plist->head;

	if (plist->head != nullptr)
		plist->head->pre = newNode;

	plist->head = newNode;

	(plist->numOfData)++;
	*/
	// 05 - 2 ����
	DNode* newNode = new DNode;
	newNode->data = data;

	newNode->pre = plist->tail->pre;
	newNode->next = plist->tail;

	plist->tail->pre->next = newNode;
	plist->tail->pre = newNode;

	
	

	(plist->numOfData)++;
}
void DInsertFront(List* plist, Data data)
{

}

int DFirst(List* plist, Data* pdata)
{
	/*
	if (plist->head == nullptr)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
	*/

	//���� 05-2
	if (plist->head->next == plist->tail)
	{
		printf_s("����\n");
		return FALSE;
	}
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int DNext(List* plist, Data* pdata)
{
	/*
	if (plist->cur->next == nullptr)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
	*/
	// ���� 05-2
	if (plist->cur->next == plist->tail)
		return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}
int DPrevious(List* plist, Data* pdata)
{
	/*
	if (plist->cur->pre == nullptr)
		return FALSE;

	plist->cur = plist->cur->pre;
	*pdata = plist->cur->data;
	return TRUE;
	*/

	//���� 05-2
	if (plist->cur->pre == plist->head)
		return FALSE;
	plist->cur = plist->cur->pre;
	*pdata = plist->cur->data;

	return TRUE;
}
Data DRemove(List* plist)
{
	//���� 05-2
	DNode* rpos = plist->cur;
	Data remv = rpos->data;

	plist->cur->pre->next = plist->cur->next;
	plist->cur->next->pre = plist->cur->pre;

	plist->cur = plist->cur->pre;

	delete rpos;
	(plist->numOfData)--;
	return remv;

}
int DCount(List* plist)
{
	return plist->numOfData;
}
