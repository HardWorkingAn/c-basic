#include <iostream>
#include <cstddef>
#include <ctime>
#include "CircularQueue.h"

#define CUS_COME_TERM 15 //고객의 주문 간격 : 초단위

#define  CHE_BUR 0 // 치즈버거 상수
#define  BUL_BUR 1 // 불고기버거 상수
#define  DUB_BUR 2 // 더블버거 상수

#define  CHE_TERM 12 // 치즈버거 제작 시간 
#define  BUL_TERM 15 // 불고기버거 제작 시간
#define  DUB_TERM 24 // 더블버거 제작 시간

int main()
{
	int makeProc = 0; //햄버거 제작 진행
	int cheOrder = 0, bulOder = 0, dubOrder = 0; //각 제작 현황
	int sec;

	Queue queue;

	QueueInit(&queue);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++)
	{
		if(sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&queue, CHE_TERM);
				cheOrder++;
				break;
			case BUL_BUR:
				Enqueue(&queue, BUL_TERM);
				bulOder++;
				break;
			case DUB_BUR:
				Enqueue(&queue, DUB_TERM);
				dubOrder++;
				break;
			}
		}
		// 전에 들어온 햄버거 제작 시간이 0이 되지 않을떄까지 Dequeue를 하지않음. 만약 더블버거가 많으면 큐에는 데이터가 쌓여 메모리 오류 발생
		// 하지만 치즈버거가 많으면 제작시간보다 주문시간이 기니 큐에는 비어있는시간이 생김
		if (makeProc <= 0 && !QIsEmpty(&queue)) 
		{
			makeProc = Dequeue(&queue);
		}
		makeProc--;
	}

	printf_s("시뮬레이션 정리\n");
	printf_s("치즈 버거 : %d \n", cheOrder);
	printf_s("불고기 버거 : %d \n", bulOder);
	printf_s("더블 버거 : %d \n", dubOrder);
	printf_s("대기 룸 사이즈 : %d\n", QUEUE_LEN);


}