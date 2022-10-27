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


//������ȸ (���� -> ���ʼ��� -> ������ ����)
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	//printf_s("%d ", GetData(bt));
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
//������ȸ
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	if (bt->left != nullptr || bt->right != nullptr)
		printf_s("( ");
	

	InorderTraverse(bt->left, action);
	//printf_s("%d ", GetData(bt));
	//void ShowIntmain�� �Լ��� action���� �ް� BTdata�� �Ű������� bt->data�� ��������μ�
	// printf_s ("%d ", data); ��� �Լ� �۵�
	action(bt->data);
	InorderTraverse(bt->right, action);

	if (bt->left != nullptr || bt->right != nullptr)
		printf_s(") ");
}
//������ȸ(���� ������� -> ��������� ������� -> ���� -> ������ ������� -> ������ ��������� �������)
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}
//���� 08-1
void DeleteTree(BTreeNode* bt)
{
	if (bt == nullptr)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf_s("%d �� ����\n", bt->data);
	delete bt;
}