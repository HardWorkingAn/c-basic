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
		newNode->next = plist->tail->next; // ���� tail�� ����� �����͸� ���� newNode�� next�� �������ְ� 
		plist->tail->next = newNode; // ���� tail�� NewNode �� �����Ѵ�.
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

		newNode->next = plist->tail->next; // ���� tail�� ����� �����͸� ���� newNode�� next�� �������ְ� 
		plist->tail->next = newNode; // ���� tail�� NewNode �� �����Ѵ�.
		plist->tail = newNode; // tail�� ���� �߰��� node�� �Ͽ� Linsert�� ���� �߰��� node�� ������ ���������ش�.
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
	//���� �ϱ� ���� �ӽ� ��ü����
	Node* rpos = plist->cur;
	Data data = rpos->data;
	

	// �����Ϸ��°� tail���
	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next) // �ڷᰡ �Ѱ� ������������
		{
			plist->tail = nullptr;
		}
		else
		{
			plist->tail = plist->before; // next�� ���� before ���� cur ���� ������ ������ ���� ����
		}
	}

	//������ ���� Ŀ���̵�
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	//����
	delete rpos;
	(plist->numOfData)--;
	return data;
}
int LCount(List* plist)
{
	return plist->numOfData;
}