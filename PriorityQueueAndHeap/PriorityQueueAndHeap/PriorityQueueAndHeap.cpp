#include <iostream>
#include "SimpleHeap.h"
//#include "UsefulHeap.h"
#include "PriorityQueue.h"

#include <string>
using namespace std;

//int DataPriorityComp(char ch1, char ch2)
int DataPriorityComp(const char* ch1, const char* ch2) //Simple heap 에서 typedef char 에서 typedef char * 로 변경
{
    //return ch1 - ch2;
    //return ch2 - ch1;
    return strlen(ch2) - strlen(ch1);
    
}

int main()
{
    
    /*
    Heap heap;
    HeapInit(&heap);
    HInsert(&heap, 'A', 1); // 최고의 우선순위
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf_s("%c ", HDelete(&heap));

	HInsert(&heap, 'A', 1); // 최고의 우선순위
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
    printf_s("%c ", HDelete(&heap));
    */
    /*
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'A'); 
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf_s("%c ", HDelete(&heap));

    HInsert(&heap, 'A'); 
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf_s("%c ", HDelete(&heap));

    while (!HIsEmpty(&heap))
    {
        printf_s("%c ", HDelete(&heap));
    }
    */
    PQueue pq;

    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, "hello world");
    PEnqueue(&pq, "Good day comender");
    PEnqueue(&pq, "Super Sonic 1");

    while (!PQIsEmpty(&pq))
    {
        //printf_s("%c ", PDequeue(&pq));
        printf_s("%s \n", PDequeue(&pq));
    }


    std::cout << "\nEnd Of Main\n";
}