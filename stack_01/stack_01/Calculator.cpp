#include "Calculator.h"
#include "ArrayBaseStack.h"
#include <cstring>
#include <cctype>

int EvalRPExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0 ; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			SPush(&stack,tok);
		}
		else
		{	
			//op �� ���� ���� �����̹Ƿ� ����Ҷ� �ڷ� ��ġ����.
			op1 = SPop(&stack);
			op2 = SPop(&stack);

			switch (tok)
			{
			case '*':
				SPush(&stack, op2 * op1);
				break;
			case '/':
				SPush(&stack, op2 / op1);
				break;
			case '+':
				SPush(&stack, op2 + op1);
				break;
			case '-':
				SPush(&stack, op2 - op1);
				break;
			}
		}
	}
	return SPop(&stack);
}