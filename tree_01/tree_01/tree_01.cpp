#include <iostream>
#include "BinaryTree.h"
#include "ExpressTree.h"

// 미리 선언 하고 정의는 메인뒤에
void ShowIntData(BTdata data);

int main()
{
    /*
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();
    BTreeNode* bt5 = MakeBTreeNode();
    BTreeNode* bt6 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeLeftSubTree(bt3, bt6);

    printf_s("%d \n", GetData(GetLeftSubTree(bt1)));

    printf_s("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

    printf_s("\n");
    //InorderTraverse(bt1);
    InorderTraverse(bt1, ShowIntData);
    printf_s("\n");
    //PostorderTraverse(bt1);
    //ShowintData 라는 void 함수를 action에 전달
    PostorderTraverse(bt1, ShowIntData);
    printf_s("\n");

    DeleteTree(bt2);
    */

    char exp[] = "12+7*";
    //char exp[] = "1+2*7";
    BTreeNode* eTree = MakeExpTree(exp);

    printf_s("전위 표기법의 수식 : ");
    ShowPrefixTypeExp(eTree);
    printf_s("\n");
	printf_s("중위 표기법의 수식 : ");
	ShowInfixTypeExp(eTree);
    printf_s("\n");
	printf_s("후위 표기법의 수식 : ");
	ShowPostfixTypeExp(eTree);
    printf_s("\n");
    printf_s("연산의 결과 : %d\n", EvaluateExpTree(eTree));
    std::cout << "\nEnd Of Main\n";
}

// 재정의한 함수 사용 
void ShowIntData(BTdata data)
{
	printf_s("%d ", data);
}