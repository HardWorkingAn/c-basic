#include <iostream>

#include "LikedRead.h"
#include "Point.h"

using namespace std;

#define ARR_MAX 10

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}
int WhoIsPrecedePoint(Point* d1, Point* d2)
{
	if (d1->x < d2->x)
		return 0;
	else
		return 1;
}
int main()
{
	/*
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
		//
		//if (head == nullptr)
		//{
		//	head = newNode2;
		//	tail = newNode2;
		//}
		//else
		//{
		//	newNode2->next = head;
		//	head = newNode2;
		//}
		//
		
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
	*/
	
	// 리스트 생성 및 초기화
	/*
	LinkedList list;
	int data;	
	ListInit(&list);
	// 정렬의 기준등륵 이걸 사용한다는 것은 comp는 nullptr 아니기 떄문에 무조건 정렬은 되지만 0과 1 바꾸면 역순으로 변경
	SetSortRule(&list, WhoIsPrecede);

	// 데이터 저장
	LInsert(&list, 11); LInsert(&list, 22);
	LInsert(&list, 33); LInsert(&list, 44);
	LInsert(&list, 55);

	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));
	
	

	//전체 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	// 3 데이터 삭제
	if (LFirst(&list, &data))
	{
		if (data == 33)
		{
			LRemove(&list);
		}
		while (LNext(&list, &data))
		{
			if (data == 33)
			{
				LRemove(&list);
			}
		}
	}
	printf("\n\n");

	//삭제후 재출력
	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);;
		}
	}
	printf("\n\n");

	LInsert(&list, 35);

	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);;
		}
	}
	printf("\n\n");
	*/
	//문제 04-3 Point 추가 데이터 재사용 04-4
	
	LinkedList list;
	//int data;
	Point* data;
	ListInit(&list);
	Point compPos;
	SetSortRule(&list, WhoIsPrecedePoint);

	// 데이터 저장
	data = new Point(); // 저장공간을 만들어 주기위한 할당
	SetPoint(data, 1, 8);
	LInsert(&list, data);

	data = new Point();
	SetPoint(data, 8, 8);
	LInsert(&list, data);

	data = new Point();
	SetPoint(data, 4, 3);
	LInsert(&list, data);

	data = new Point();
	SetPoint(data, 6, 6);
	LInsert(&list, data);

	data = new Point();
	SetPoint(data, 7, 3);
	LInsert(&list, data);
	

	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));

	//전체 출력
	if (LFirst(&list, &data))
	{
		//printf("%d ", data);
		ShowPoint(data);
		while (LNext(&list, &data))
		{
			//printf("%d ", data);
			ShowPoint(data);
		}
	}
	// x = 8 인 데이터 삭제
	SetPoint(&compPos, 8, 0);
	if (LFirst(&list, &data))
	{
		if (PointComp(data,&compPos) == 1)
		{
			data = LRemove(&list);
			delete(data);
		}
		while (LNext(&list, &data))
		{
			if (PointComp(data, &compPos) == 1)
			{
				data = LRemove(&list);
				delete(data);
			}
		}
	}
	printf("\n\n");

	//삭제후 재출력
	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		//printf("%d ", data);
		ShowPoint(data);
		while (LNext(&list, &data))
		{
			//printf("%d ", data);
			ShowPoint(data);
		}
	}
	printf("\n\n");

	//중간 삽입 확인
	data = new Point();
	SetPoint(data, 5, 2);
	LInsert(&list, data);

	//전체 출력
	if (LFirst(&list, &data))
	{
		//printf("%d ", data);
		ShowPoint(data);
		while (LNext(&list, &data))
		{
			//printf("%d ", data);
			ShowPoint(data);
		}
	}
    std::cout << "\nEnd Of Main\n";
}