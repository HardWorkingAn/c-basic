#include "SimpleHeap.h"


void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	//�߰�
	ph->comp = pc;
}
int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) // �θ� ����� �ε��� �� ��ȯ
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
// �� ���� �ڽ� ����� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
int GetHiPriChildIdx(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData) // ���� �ڽĳ�尡 ������� 0 ���� �ڽĳ���� �迭 ��ġ �� ���� �� ������ ���Ͽ� Ȯ��
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // �ڽĳ�尡 ���� �ϳ��� �����Ѵٸ�
		return GetLChildIDX(idx);
	else
	{
		//if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) // �켱������ ���� �������� ������ �������� �켱������ �� ���ٸ�
		//	return GetRChildIDX(idx); // ������ �ڽ� �ε��� �� ����
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx); // �ƴϸ� ���� �ڽ� �ε��� �� ����
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

	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) // ���� child�� �ڽĳ�尡 ������� 0
	{
		//if (lastElem.pr <= ph->heapArr[childIdx].pr) //������ ����� �켱������ �ڽĳ�� ���� �켱������ �� ������ �ٷ� ��� �Ǿ����� �̵�
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
		{
			break;
		}
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // ���� child�� �ڽ� ��尡 �ִ��� Ȯ���ϱ� ���� ���� ��  �ڽ��� ������� 
	}
	ph->heapArr[parentIdx] = lastElem;
	(ph->numOfData)--;
	return retData;
}