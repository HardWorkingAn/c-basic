#include <iostream>
#include "CircularQueue.h"
#include "DeQue.h"
using namespace std;

int main()
{

    /*
    Queue q;
    QueueInit(&q);

    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);

    while (!QIsEmpty(&q))
    {
        printf_s("%d ", Dequeue(&q));
    }
    */

    // 디큐
    Deque deq;
    DequeInit(&deq);

    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    while (!DQIsEmpty(&deq))
    {
        printf_s("%d ", DQRemoveFirst(&deq));
    }
    printf_s("\n");


	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);
    
	while (!DQIsEmpty(&deq))
	{
		printf_s("%d ", DQRemoveLast(&deq));
	}
	printf_s("\n");

    std::cout << "\nEnd Of Main\n";
}