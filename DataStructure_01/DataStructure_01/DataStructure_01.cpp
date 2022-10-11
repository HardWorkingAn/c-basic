#pragma warning(disable:4996)

#include <iostream>
#include <sstream>
#include <algorithm>
//#include <list> // STL list
#include "ArrayList.h" //구현 list
#include "Point.h"
#include "NameCard.h"
using namespace std;


//검색
/*
//순차검색
int LinearSearch(int ar[], int len, int target)
{
    int i;
    int Search_count = 0;
    for (i=0; i<len; ++i)
    {
        Search_count += 1;
        if (ar[i] == target)
        {
            cout << "Search_count = " << Search_count << endl;
            return i;
        }
    }
    cout << "Search_count = " << Search_count << endl;
    return -1; // 못 찾을 경우
}

int Binary_Search(int ar[], int len, int target)
{
    int Search_count = 0;

    int first = 0;
    int last = len - 1;
    int mid;
    
    while (first <= last)
    {
        Search_count += 1;
        mid = (first + last) / 2; // 중앙탐색
        
        if (target == ar[mid])
        {
            cout << "Search_count = " << Search_count << endl;
            return mid; // 찾을 경우
        }
        else
        {
            if (target < ar[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    cout << "Search_count = " << Search_count << endl;
    return -1; // 못 찾을 경우
}
*/
//재귀함수
/*
int re_i = 0;
void recursize(int num)
{
    if(num <= 0){
        return;
	}
	printf(" 재귀함수 호출  %d \n", num);
	recursize(num-1);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
// 이진탐색 피보나치구연
int Pibo_Binary_Search(int ar[], int first, int last, int target)
{
	int Search_count = 0;

	int mid;

    if (first > last)
        return -1;
    mid = (last + first) / 2;
    if (ar[mid] == target)
        return mid;
    else if (target < ar[mid])
        return Pibo_Binary_Search(ar, first, mid - 1, target);
    else
        return Pibo_Binary_Search(ar, mid + 1, last, target);
}

int Fibonacci(int n) //피나보치 수열
{
    printf("function call param : %d\n", n);
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return Fibonacci(n-2) + Fibonacci(n-1);
}
void HanoiTower(int num, char from, char by, char to)
{
    if(num == 1)
        printf("원반1을 %c 에서 %c로 이동\n", from, to);
    else
    {
        HanoiTower(num - 1, from, to, by);
        printf("원반%d을(를) %c 에서 %c로 이동\n",num, from, to);
        HanoiTower(num - 1, by, from, to);
    }
}
*/
// list
int main()
{
    // 개인 연습
    /*cout << "Hello World!\n";
    int arr[10] = { 0,2,5,7,3,7,2,7,6 };
    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }
    cout << sum << endl;
    string test1;
    stringstream stream(test1);
    string token;

    while (getline(std::cin, token, ';'))
    {
        cout << token << endl;
    }*/

    // 순차, 이진검색
    /*
    int i_arr[] = { 1,6,3,7,9,8,2 };
    int idx;
    //순차탐색
    cout << "binarySearch(순차탐색)\n";
    idx = LinearSearch(i_arr, sizeof(i_arr) / sizeof(int), 9);
    if (idx == -1)
        printf("찾을 수 없음\n");
    else
        printf("타겟 저장 인덱스 : %d 번째\n", idx);

    //이진탐색
    //이진 탐색은 정렬이 되어있어야 하므로 잠시 정렬 STL 사용

    int copy_i_arr[sizeof(i_arr) / sizeof(int)];
    copy(i_arr, i_arr + sizeof(i_arr) / sizeof(int), copy_i_arr);
    sort(copy_i_arr, copy_i_arr + sizeof(copy_i_arr) / sizeof(int));

    cout << "binarySearch(이진탐색)\n";
    idx = Binary_Search(copy_i_arr, sizeof(copy_i_arr) / sizeof(int), 9);
    if (idx == -1)
        printf("찾을 수 없음\n");
    else
        printf("타겟 저장 인덱스 : %d 번째\n", idx);

    idx = Binary_Search(copy_i_arr, sizeof(copy_i_arr) / sizeof(int), 4);
    if (idx == -1)
        printf("찾을 수 없음\n");
    else
        printf("타겟 저장 인덱스 : %d 번째\n", idx);


    cout << "----------------------- 탐색 시간복잡도 최악 기준 -----------------------------\n";
    cout << "순차탐색 O(N) 와 이진탐색 O(logN) 차이\n";
    int test_arr1[50] = { 0, };
    int test_arr2[500] = { 0, };
	int* ptest_arr3 = new int[5000];
	*ptest_arr3 = { 0, };
    int* ptest_arr4{ new int[50000]{0,} };
    int& ref4 = *ptest_arr4;
    
	//순차탐색
	cout << "binarySearch(순차탐색)\n";
	idx = LinearSearch(test_arr1, sizeof(test_arr1) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
	idx = LinearSearch(test_arr2, sizeof(test_arr2) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
	idx = LinearSearch(ptest_arr3, _msize(ptest_arr3) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
	idx = LinearSearch(ptest_arr4, _msize(ptest_arr4) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);

	cout << "binarySearch(이진탐색)\n";
	idx = Binary_Search(test_arr1, sizeof(test_arr1) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
	idx = Binary_Search(test_arr2, sizeof(test_arr2) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
	idx = Binary_Search(ptest_arr3, _msize(ptest_arr3) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
	idx = Binary_Search(ptest_arr4, _msize(ptest_arr4) / sizeof(int), 9);
	if (idx == -1)
		printf("찾을 수 없음\n");
	else
		printf("타겟 저장 인덱스 : %d 번째\n", idx);
*/

    // 재귀함수
    /*
    // 재귀함수
    recursize(100);
    cout << factorial(10) << endl;

    //for (int i = 1; i <= 5; i++)
    //{
    //    cout << Fibonacci(i) << " ";
    //}
    Fibonacci(7);
    
    //이진탐색 재귀함수 구현
    int i_arr[] = { 1,6,3,7,9,8,2 }; // 7개의 숫자 0~6 인덱스
	sort(i_arr, i_arr + sizeof(i_arr) / sizeof(int));

    int idx;
    idx = Pibo_Binary_Search(i_arr, 0, sizeof(i_arr) / sizeof(int) - 1, 9);
    if (idx == -1)
        printf("탐색실패 \n");
    else
        printf("탐색 인덱스 위치 : %d\n", idx);

	idx = Pibo_Binary_Search(i_arr, 0, sizeof(i_arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		printf("탐색실패 \n");
	else
		printf("탐색 인덱스 위치 : %d\n", idx);

    HanoiTower(2, 'A', 'B', 'C');
    */

    // INT형 list  쓸려면 Arraylist.h typedef int 형으로 변경
    /*
    list<int> STL_List;
    List craete_List;
    int data; //리스트안 저장되어 있는 데이터의 값을 따로 가져와 저장하기 위한 변수

    ListInit(&craete_List);

    LInsert(&craete_List, 11);
    LInsert(&craete_List, 22);
    LInsert(&craete_List, 33);
    LInsert(&craete_List, 44);
    LInsert(&craete_List, 55);
    
    printf_s("현재 데이터의 수 : %d \n", LCount(&craete_List));

    if (LFirst(&craete_List, &data))
    {
        printf("%d ", data);

        while (LNext(&craete_List,&data))
        {
            printf("%d ", data);
        }
    }
    printf("\n");

    if (LFirst(&craete_List, &data)) // 처음 위치를 잡아주기위한 if문, 값이 아예 없다면 -1를 리턴함
    {
        if (data == 22)
            LRemove(&craete_List); //현제 0번 배열에 저장되어있는 값이 22번이라면 0번 배열안에 있는 값을 제거
        
        while (LNext(&craete_List, &data)) // 이후 첫 위치를 잡아주었기 때문에 다음 자료도 있는지 확인
        {
            if (data == 22)
                LRemove(&craete_List);
        }
    }

    printf("현재 데이터를 삭제하고 남은 데이터의 수 : %d\n", LCount(&craete_List));

	if (LFirst(&craete_List, &data))
	{
		printf("%d ", data);

		while (LNext(&craete_List, &data))
		{
			printf("%d ", data);
		}
	}

    cout << endl;

    //문제 03-1 

    List answer_list;

    ListInit(&answer_list);
    for (int i = 1; i < 10; i++) 
        LInsert(&answer_list, i);

    if (LFirst(&answer_list, &data))
    {
        printf("%d ", data);

        while (LNext(&answer_list, &data))
        {
            printf("%d ", data);
        }
    }
    
    if (LFirst(&answer_list, &data)) {

        if (data % 2 == 0 || data % 3 == 0)
            LRemove(&answer_list);

        while (LNext(&answer_list,&data))
        {
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&answer_list);
        }

    }
    cout << endl;
	if (LFirst(&answer_list, &data))
	{
		printf("%d ", data);

		while (LNext(&answer_list, &data))
		{
			printf("%d ", data);
		}
	}
    */

    // Point list
    /*
    List point_list;
    
    Point compPos;
    Point* ppos;

    ListInit(&point_list);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&point_list, ppos);
    

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&point_list, ppos);
    

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&point_list, ppos);
    

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&point_list, ppos);
    

	// 저장된 데이터의 출력 
	printf("현재 데이터의 수: %d \n", LCount(&point_list));

	if (LFirst(&point_list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&point_list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&point_list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&point_list);
			free(ppos);
		}

		while (LNext(&point_list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&point_list);
				free(ppos);
			}
		}
	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&point_list));

	if (LFirst(&point_list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&point_list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n1\n");

    char* pA = "abcd";
    char a[] = { "아야아아아" };

    cout << a << endl;
    cout << pA << endl;
    */
    
    //문제 03-2 NameCard List 적용
    List NameCardList;
    
    ListInit(&NameCardList); //초기화
    
    NameCard* pName = new NameCard();
    pName = MakeNameCard("test", "010-1111-2222");
    LInsert(&NameCardList, pName);

	pName = new NameCard();
	pName = MakeNameCard("test2", "010-1234-5678");
	LInsert(&NameCardList, pName);

	pName = new NameCard();

	pName = MakeNameCard("한글닉", "010-2221-6566");
	LInsert(&NameCardList, pName);

    if (LFirst(&NameCardList, &pName))
    {
        ShowNameCardInfo(pName);
        while (LNext(&NameCardList, &pName))
        {
            printf("\n");
            ShowNameCardInfo(pName);
        }
    }
    printf("\n"); printf("\n");

    char* searchChar = "한글닉1";
    if (LFirst(&NameCardList, &pName))
    {
        if (NameCompare(pName, searchChar) == 0)
        {
            ShowNameCardInfo(pName);
        }
        else
        {
            while (LNext(&NameCardList, &pName))
            {
				if (NameCompare(pName, searchChar) == 0)
				{
					ShowNameCardInfo(pName);
                    break;
				}
                else if (NameCompare(pName, searchChar) != 0 && (NameCardList.numOfData - 1) == NameCardList.curPosition)
                {
                    printf("찾는 값이 없습니다. \n");
                }
            }
        }
    }
    printf("\n\n");

	searchChar = "한글닉";
	if (LFirst(&NameCardList, &pName))
	{
		if (NameCompare(pName, searchChar) == 0)
		{
            ChangePhoneNum(pName, "010-5555-8888");
			ShowNameCardInfo(pName);
		}
		else
		{
			while (LNext(&NameCardList, &pName))
			{
				if (NameCompare(pName, searchChar) == 0)
				{
                    ChangePhoneNum(pName, "010-5555-8888");
					ShowNameCardInfo(pName);
					break;
				}
				else if (NameCompare(pName, searchChar) != 0 && (NameCardList.numOfData - 1) == NameCardList.curPosition)
				{
					printf("찾는 값이 없습니다. \n");
				}
			}
		}
	}
    searchChar = "test2";
    bool removeCheck = FALSE;
	if (LFirst(&NameCardList, &pName))
	{
		if (NameCompare(pName, searchChar) == 0)
		{
            LRemove(&NameCardList);
		}
		else
		{
			while (LNext(&NameCardList, &pName))
			{
				if (NameCompare(pName, searchChar) == 0)
				{
                    LRemove(&NameCardList);
                    break;
				}
				else if (NameCompare(pName, searchChar) != 0 && (NameCardList.numOfData - 1) == NameCardList.curPosition)
				{
					printf("찾는 값이 없습니다. \n");
				}
			}
		}
	}
    printf("\n\n");

	if (LFirst(&NameCardList, &pName))
	{
		ShowNameCardInfo(pName);
		while (LNext(&NameCardList, &pName))
		{
			printf("\n");
			ShowNameCardInfo(pName);
		}
	}

}
