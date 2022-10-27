#include "ExpressTree.h"
#include "ListBaseStack.h"
#include <iostream>
#include <cstring>
#include <cctype>

BTreeNode* MakeExpTree(char exp[]) // ���� Ʈ���� �����ϴ� �Լ�
{
	Stack stack;
	BTreeNode* pnode;

	int expLen = strlen(exp);
	int i;
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i])) // ���� exp[i]�� ���ڶ��
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}

	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode* bt) // ���� Ʈ���� ����ϴ� �Լ�
{
	int op1, op2;

	if (GetLeftSubTree(bt) == nullptr && GetRightSubTree(bt) == nullptr)
	{
		return GetData(bt);
	}


	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf_s("%d ", data);
	else
		printf_s("%c ", data);

}

void ShowPrefixTypeExp(BTreeNode* bt) // ������ ǥ��
{
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode* bt) // ������ ǥ��
{
	InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode* bt) // ������ ǥ��
{
	PostorderTraverse(bt, ShowNodeData);
}

