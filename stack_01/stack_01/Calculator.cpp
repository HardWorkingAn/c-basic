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
			//op 가 먼저 들어가면 스택이므로 계산할때 뒤로 배치힌다.
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