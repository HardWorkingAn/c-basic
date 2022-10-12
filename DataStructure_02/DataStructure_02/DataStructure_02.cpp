#include <iostream>

#include "LikedRead.h"

using namespace std;

#define ARR_MAX 10
int main()
{
	node* head = nullptr;
	node* tail = nullptr;
	node* cur = nullptr;

	node* newNode = nullptr;

    // int arr[ARR_MAX];
    // int readCount = 0;
    int readData;
    int i;

 //   while (readCount < ARR_MAX)
 //   {
 //       printf("자연수 입력 : ");
 //       scanf("%d", &readData);
 //       if (readData < 1)
 //       {
 //           break;
 //       }
 //       arr[readCount++] = readData;
 //   
 //   }
	//for (i = 0; i < readCount; i++)
	//	printf("%2d ", arr[i]);

	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)
		{
			break;
		}

		newNode = new node();
		newNode->data = readData;
		newNode->next = nullptr;
		
		if (head == nullptr)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	printf("입력 받은 데이터 전체출력\n");

	if (head == nullptr)
	{
		printf("입력 받은 데이터가 없습니다.\n");
	}
	else
	{
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != nullptr)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
		printf("\n\n");
	}

	//메모리 해제
	if (head == nullptr)
	{
		printf("데이터가 없습니다.\n");
		//return 0;
	}
	else
	{
		node* delNode = head;
		node* delNextNode = delNode->next; // delete하게 되면 next의 위치를 모르니 먼저 next의 위치를 가져오기

		printf("%d 데이터 삭제\n", delNode->data);
		delete delNode; //현제 delNode 의 포인터 위치에 있는 데이터를 삭제

		while (delNextNode != nullptr)
		{
			delNode = delNextNode;
			delNextNode = delNode->next;

			printf("%d 데이터 삭제\n", delNode->data);
			delete delNode; //현제 delNode 의 포인터 위치에 있는 데이터를 삭제
		}
	}
	printf("\n\n 문제 4-1 & 4-2 \n\n");
	//문제 04 - 1 , 04 - 2이어서
	node* newNode2 = nullptr;
	head = nullptr;

	head = new node(); // 4-2 문제 더미추가
	tail = head;

	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)
		{
			break;
		}

		newNode2 = new node();
		newNode2->data = readData;
		newNode2->next = nullptr;
		
		//문제 4-2 추가
		tail->next = newNode2;
		tail = newNode2;
		// 문제 4-1 부분 4-2 차이나서 주석처리
		/* 
		if (head == nullptr)
		{
			head = newNode2;
			tail = newNode2;
		}
		else
		{
			newNode2->next = head;
			head = newNode2;
		}
		*/
		
	}
	printf("\n");
	//if (head == nullptr) 이 조건은 4-1 조건 아래 조건은 4-2조건
	if (head == tail) //위에 tail 에 head 를 처음에 대입하기 떄문에 조건처리
	{
		printf("입력 받은 데이터가 없습니다.\n");
	}
	else
	{
		cur = head;
		//printf("%d ", cur->data); 4-1문제 4-2에는 처음 값은 더미이기 떄문에 print할 값이 없다.
		while (cur->next != nullptr)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
		printf("\n\n");
	}

	//메모리 해제
	if (head == tail)
	{
		printf("데이터가 없습니다.\n");
		return 0;
	}
	else
	{
		node* delNode = head;
		node* delNextNode = delNode->next; // delete하게 되면 next의 위치를 모르니 먼저 next의 위치를 가져오기

		printf("더미 데이터 삭제\n");
		delete delNode; //현제 delNode 의 포인터 위치에 있는 데이터를 삭제

		while (delNextNode != nullptr)
		{
			delNode = delNextNode;
			delNextNode = delNode->next;

			printf("%d 데이터 삭제\n", delNode->data);
			delete delNode; //현제 delNode 의 포인터 위치에 있는 데이터를 삭제
		}
	}
    std::cout << "\nEnd Of Main\n";
}