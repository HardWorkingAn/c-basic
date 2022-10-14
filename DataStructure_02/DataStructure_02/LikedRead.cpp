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
	plist->head->next = newNode; //현제 더미의 next 값을 newnode를 바꾸기 떄문에 앞쪽으로 추가되는 형식 132p 그림

	(plist->numOfData)++; //더미를 구현해놓고 해드의 next만 변경하기 때문에 떄문에 값이 한곳에서만 증가함
}

void SInsert(List* plist, LData data) //중간 삽입 또는 
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

void LInsert(List* plist, LData data) // ※ cpp에만 선언된 함수는 사용할 때 항상 위에 두자
{
	if (plist->comp == nullptr)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List* plist, LData* pdata) 
{
	if (plist->head->next == nullptr)
		return FALSE; // 첫번째 값이 존재하지 않을 경우 0으로 리턴

	plist->before = plist->head; // before을 head를 가지게 함으로서 before과 head는 같은 포인터를 가짐
	plist->cur = plist->head->next; // 더미 다음 포인터를 cur에 저장 -> cur는 첫번째 데이터 위치를 의미

	*pdata = plist->cur->data; // 첫번째 노드에 데이터 전달
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == nullptr) // First가 되었다면 cur 다음값이 있는지 확인
		return FALSE;

	plist->before = plist->cur; // 현재 포인터을 before에 저장
	plist->cur = plist->cur->next; // cur 를 next위치로 이동

	*pdata = plist->cur->data; // 첫번째 노드에 데이터 전달
	return TRUE;
}

LData LRemove(List* plist)
{
	node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next; //이전의 리스트 에 연결된 포인터를 현제커서의 다음 주소로 연결
	plist->cur = plist->before;  //현제 커서를 전으로 조정

	delete(rpos); // 미리 등륵된 제거할 list를 힙메모리 제거
	(plist->numOfData)--;
	return rdata; // 제거된 데이터 값을 리턴
}
int LCount(List* plist)
{
	return plist->numOfData;
}

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) //메인의 WhoIsPrecde를 통해 0인지 1인지 가져온다.
{
	plist->comp = comp;
}

