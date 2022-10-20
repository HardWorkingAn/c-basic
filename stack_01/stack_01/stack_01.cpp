#pragma warning(disable:4996)

#include <iostream>
#include "ArrayBaseStack.h"
#include "InfixToPostfix.h"
#include "Calculator.h"

using namespace std;



int main()
{
    /*
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 3); SPush(&stack, 7);
    SPush(&stack, 5); SPush(&stack, 8); 
	SPush(&stack, 1);

    while (!SIsEmpty(&stack)) //앞에 !(Not) 붙어있음
    {
        printf_s("%d ", SPop(&stack));
    }
    */
    // 혼자 중위 후위 변환 연습
    /*
    // 중위 후위로 변환
    Stack stack;
    StackInit(&stack);

    string str = "3*2+4";
    char ch[100];
    strcpy(ch, str.c_str());
    string str2;
    cout << ch << endl;
    for (char c : ch)
    {
        if (c != '\0') {
            if (c == '*' || c == '/' || c == '+' || c == '-')
            {
                SPush(&stack, c);
            }
            else
            {
                str2 += c;
            }
        }
        else
        {
            break;
        }
    }
	while (!SIsEmpty(&stack))
	{
        str2 += SPop(&stack);
	}

    cout << str2 << endl;
    */

    /*
    char exp1[] = "3-2+4";
    ConvToRPNExp(exp1);
    printf_s("%s \n", exp1);
    char exp2[] = "7+4*7+2";
	ConvToRPNExp(exp2);
	printf_s("%s \n", exp2);
    */
    char exp3[] = "(6*(1-2)+3)*(5-2)";
	ConvToRPNExp(exp3);
	printf_s("%s \n", exp3);
    
    printf_s("%s = %d\n", exp3,EvalRPExp(exp3));

    
    std::cout << "\nEnd Of File\n";
}