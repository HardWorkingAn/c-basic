#include <iostream>
#include "CLinkedList.h" // 에러방지 막음
#include <string>
using namespace std;

int main()
{
    /*
    List list;
    int data, i, nodeNum;
    
    ListInit(&list);

    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    if (LFirst(&list, &data))
    {
        printf_s("%d ", data);
        for (i = 0; i < LCount(&list) - 1; i++)
        {
            LNext(&list,&data);
            printf_s("%d ", data);
        }
    }
    printf_s("\n");

    //2의 배수 삭제
    nodeNum = LCount(&list);
    if (nodeNum != 0)
    {
        LFirst(&list, &data);
        if (data % 2 == 0)
            LRemove(&list);
        for (i = 0; i < nodeNum - 1; i++)
        {
            LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
        }
    }
    printf_s("\n");

	if (LFirst(&list, &data))
	{
		printf_s("%d ", data);
		for (i = 0; i < LCount(&list) - 1; i++)
		{
			LNext(&list, &data);
			printf_s("%d ", data);
		}
	}
    */
	List list;
    string data;
	int i, nodeNum;
	int NextNum;

	ListInit(&list);

	LInsert(&list, "테스트1");
	LInsert(&list, "테스트2");
	LInsert(&list, "테스트3");
	LInsertFront(&list, "테스트4");
	

	if (LFirst(&list, &data))
	{
		printf_s("%s ", data.c_str());
		for (i = 0; i < LCount(&list) - 1; ++i)
		{
			LNext(&list, &data);
			printf_s("%s ", data.c_str());
		}
	}
	printf_s("\n");


	printf_s("선택 일 : ");
	scanf_s("%d", &NextNum);
	if (LFirst(&list, &data))
	{
		if (NextNum == 0)
		{
			printf_s("%s 가 당직자입니다.\n", data.c_str());
		}
		else {
			for (i = 0; i < NextNum; ++i)
			{
				LNext(&list, &data);
			}
			printf_s("%s 가 당직자입니다.\n", data.c_str());
		}
		
	}
	printf_s("\n");

    std::cout << "\nEnd Of Main\n";
}