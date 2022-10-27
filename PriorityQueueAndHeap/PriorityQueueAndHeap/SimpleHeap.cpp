#include "SimpleHeap.h"


void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	//추가
	ph->comp = pc;
}
int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) // 부모 노드의 인덱스 값 반환
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}
// 두 개의 자식 노드중 높은 우선순위의 자식 노드 인덱스 값 변환
int GetHiPriChildIdx(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData) // 만약 자식노드가 없을경우 0 리턴 자식노드의 배열 위치 와 값의 총 갯수를 비교하여 확인
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // 자식노드가 왼쪽 하나만 존재한다면
		return GetLChildIDX(idx);
	else
	{
		//if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) // 우선순위는 값이 낮을수록 높으니 오른쪽이 우선순위가 더 높다면
		//	return GetRChildIDX(idx); // 오른쪽 자식 인덱스 값 리턴
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx); // 아니면 왼쪽 자식 인덱스 값 리턴
	}
}
//void HInsert(Heap* ph, HData data, Proiority pr)
//{
//	int idx = ph->numOfData + 1;
//	HeapElem nelem = { pr, data };
//	
//	while (idx != 1)
//	{
//		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
//		{
//			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
//			idx = GetParentIDX(idx);
//		}
//		else
//			break;
//	}
//	ph->heapArr[idx] = nelem;
//	(ph->numOfData)++;
//}

void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1;
	//HeapElem nelem = { pr, data };
	
	while (idx != 1)
	{
		//if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	//ph->heapArr[idx] = nelem;
	ph->heapArr[idx] = data;
	(ph->numOfData)++;
}
HData HDelete(Heap* ph)
{
	//HData retData = (ph->heapArr[1]).data;
	//HeapElem lastElem = ph->heapArr[ph->numOfData];
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) // 만약 child의 자식노드가 없을경우 0
	{
		//if (lastElem.pr <= ph->heapArr[childIdx].pr) //마지막 노드의 우선순위가 자식노드 보다 우선순위가 더 높으면 바로 노드 맨앞으로 이동
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
		{
			break;
		}
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // 이후 child의 자식 노드가 있는지 확인하기 위한 대입 및  자식이 없을경우 
	}
	ph->heapArr[parentIdx] = lastElem;
	(ph->numOfData)--;
	return retData;
}