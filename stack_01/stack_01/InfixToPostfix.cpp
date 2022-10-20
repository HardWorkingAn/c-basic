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

	memset(convExp, 0, sizeof(char) * expLen + 1); // convExp 배열에 0이란 숫자를 sizeof(char) * expLen + 1 만큼 초기화 해준다.
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) //isdigit(tok) tok이 문자인지 숫자인지 검색 숫자면 1 아니면 0 리턴
		{
			convExp[idx++] = tok; //후위 연산이기 때문에 대입후 idx값이 증가
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
					// )는 따로 push 되지않고 스택 안에 저장된 4연산자를 pop 하여 저장
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
				// 비어있으면 true 없으면 fasle 인데 ! 붙이니깐  반대연산됨
				//또한 WhoPrecOp 에서 현제 스택에 저장되어 있는게 tok 보다 연산순위가 높거나 같으면 진행
				// conExp에 스택에서 Pop 하여 저장
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) 
				{
					convExp[idx++] = SPop(&stack);
				}
				// tok은 그대로 스택에 저장
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