#pragma once

typedef int BTdata;

typedef struct _BTreeNode
{
	BTdata data;
	_BTreeNode* left;
	_BTreeNode* right;
} BTreeNode;


BTreeNode* MakeBTreeNode(void);
BTdata GetData(BTreeNode* bt);
void SetData(BTreeNode* bt,BTdata data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

//�Լ��� �����Ǹ� �Ѵ�.
typedef void (*VisitFuncPtr)(BTdata data);

//������ȸ (���� -> ���ʼ��� -> ������ ����)
//void PreorderTraverse(BTreeNode* bt)
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);

//������ȸ (���� ����Ʈ�� -> ���� -> ������ ����Ʈ�� ����
//void InorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action); // �Լ� ������ ����

//������ȸ
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

//���� 08-1
void DeleteTree(BTreeNode* bt);