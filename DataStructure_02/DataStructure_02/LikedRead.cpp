#include "LikedRead.h"

void ListInit(List* plist) 
{
	plist->head = new node();
	plist->head->next = nullptr;
	plist->comp = nullptr;
	plist->numOfData = 0;
}




void FInsert(List* plist, LData data) 
{
	node* newNode = new node();
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode; //���� ������ next ���� newnode�� �ٲٱ� ������ �������� �߰��Ǵ� ���� 132p �׸�

	(plist->numOfData)++; //���̸� �����س��� �ص��� next�� �����ϱ� ������ ������ ���� �Ѱ������� ������
}

void SInsert(List* plist, LData data) //�߰� ���� �Ǵ� 
{
	node* newNode = new node();
	node* pred = plist->head;
	newNode->data = data;

	while (pred->next != nullptr && plist->comp(data,pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data) // �� cpp���� ����� �Լ��� ����� �� �׻� ���� ����
{
	if (plist->comp == nullptr)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List* plist, LData* pdata) 
{
	if (plist->head->next == nullptr)
		return FALSE; // ù��° ���� �������� ���� ��� 0���� ����

	plist->before = plist->head; // before�� head�� ������ �����μ� before�� head�� ���� �����͸� ����
	plist->cur = plist->head->next; // ���� ���� �����͸� cur�� ���� -> cur�� ù��° ������ ��ġ�� �ǹ�

	*pdata = plist->cur->data; // ù��° ��忡 ������ ����
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == nullptr) // First�� �Ǿ��ٸ� cur �������� �ִ��� Ȯ��
		return FALSE;

	plist->before = plist->cur; // ���� �������� before�� ����
	plist->cur = plist->cur->next; // cur �� next��ġ�� �̵�

	*pdata = plist->cur->data; // ù��° ��忡 ������ ����
	return TRUE;
}

LData LRemove(List* plist)
{
	node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next; //������ ����Ʈ �� ����� �����͸� ����Ŀ���� ���� �ּҷ� ����
	plist->cur = plist->before;  //���� Ŀ���� ������ ����

	delete(rpos); // �̸� ��� ������ list�� ���޸� ����
	(plist->numOfData)--;
	return rdata; // ���ŵ� ������ ���� ����
}
int LCount(List* plist)
{
	return plist->numOfData;
}

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) //������ WhoIsPrecde�� ���� 0���� 1���� �����´�.
{
	plist->comp = comp;
}

