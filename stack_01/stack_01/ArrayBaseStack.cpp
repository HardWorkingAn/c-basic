#include <iostream>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}
int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
	
}

void SPush(Stack* pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack* pstack)
{
	Data data;
	if (SIsEmpty(pstack))
	{
		printf_s("���� ����� ���� �����ϴ�.\n");
		exit(-1);
	}
	data = pstack->stackArr[pstack->topIndex];
	(pstack->topIndex)--;

	return data;
}

Data SPeek(Stack* pstack) // Topindex�� �����ϸ鼭 ���
{
	if (SIsEmpty(pstack))
	{
		printf_s("���� ����� ���� �����ϴ�.\n");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
