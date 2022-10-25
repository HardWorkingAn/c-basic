#include "BinaryTree.h"
#include <iostream>


BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newNode = new BTreeNode();
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
BTdata GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, BTdata data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != nullptr)
		delete main->left;
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != nullptr)
		delete main->right;
	main->right = sub;
}


//전위순회 (메인 -> 왼쪽서브 -> 오른쪽 서브)
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	//printf_s("%d ", GetData(bt));
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
//중위순회
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	if (bt->left != nullptr || bt->right != nullptr)
		printf_s("( ");
	

	InorderTraverse(bt->left, action);
	//printf_s("%d ", GetData(bt));
	//void ShowIntmain의 함수를 action으로 받고 BTdata의 매개변수는 bt->data로 사용함으로서
	// printf_s ("%d ", data); 라는 함수 작동
	action(bt->data);
	InorderTraverse(bt->right, action);

	if (bt->left != nullptr || bt->right != nullptr)
		printf_s(") ");
}
//후위순회(왼쪽 하위노드 -> 하위노드의 상위노드 -> 메인 -> 오른쪽 하위노드 -> 오른쪽 하위노드의 상위노드)
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}
//문제 08-1
void DeleteTree(BTreeNode* bt)
{
	if (bt == nullptr)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf_s("%d 를 삭제\n", bt->data);
	delete bt;
}