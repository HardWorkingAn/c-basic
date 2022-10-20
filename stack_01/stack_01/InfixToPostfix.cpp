#pragma warning(disable:4996)

#include "InfixToPostfix.h"
#include "ArrayBaseStack.h"
#include <cstring>
#include <iostream>
#include <cctype>

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
	{
		return 1;
	}
	else if (op1Prec < op2Prec)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen+1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // convExp �迭�� 0�̶� ���ڸ� sizeof(char) * expLen + 1 ��ŭ �ʱ�ȭ ���ش�.
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) //isdigit(tok) tok�� �������� �������� �˻� ���ڸ� 1 �ƴϸ� 0 ����
		{
			convExp[idx++] = tok; //���� �����̱� ������ ������ idx���� ����
		}
		else
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
				while (1)
				{
					// )�� ���� push �����ʰ� ���� �ȿ� ����� 4�����ڸ� pop �Ͽ� ����
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '*':
			case '/':
			case '+':
			case '-':
				// ��������� true ������ fasle �ε� ! ���̴ϱ�  �ݴ뿬���
				//���� WhoPrecOp ���� ���� ���ÿ� ����Ǿ� �ִ°� tok ���� ��������� ���ų� ������ ����
				// conExp�� ���ÿ��� Pop �Ͽ� ����
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) 
				{
					convExp[idx++] = SPop(&stack);
				}
				// tok�� �״�� ���ÿ� ����
				SPush(&stack, tok);
				break;

			}
		}
	}

	while (!SIsEmpty(&stack))
	{
		convExp[idx++] = SPop(&stack);
	}

	strcpy(exp, convExp);
	free(convExp);
}