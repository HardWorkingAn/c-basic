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

//함수를 재정의를 한다.
typedef void (*VisitFuncPtr)(BTdata data);

//전위순회 (메인 -> 왼쪽서브 -> 오른쪽 서브)
//void PreorderTraverse(BTreeNode* bt)
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);

//중위순회 (왼쪽 서브트리 -> 메인 -> 오른쪽 서브트리 순서
//void InorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action); // 함수 재정의 사용법

//후위순회
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

//문제 08-1
void DeleteTree(BTreeNode* bt);