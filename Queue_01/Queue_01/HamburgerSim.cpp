#include <iostream>
#include <cstddef>
#include <ctime>
#include "CircularQueue.h"

#define CUS_COME_TERM 15 //���� �ֹ� ���� : �ʴ���

#define  CHE_BUR 0 // ġ����� ���
#define  BUL_BUR 1 // �Ұ����� ���
#define  DUB_BUR 2 // ������� ���

#define  CHE_TERM 12 // ġ����� ���� �ð� 
#define  BUL_TERM 15 // �Ұ����� ���� �ð�
#define  DUB_TERM 24 // ������� ���� �ð�

int main()
{
	int makeProc = 0; //�ܹ��� ���� ����
	int cheOrder = 0, bulOder = 0, dubOrder = 0; //�� ���� ��Ȳ
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
		// ���� ���� �ܹ��� ���� �ð��� 0�� ���� ���������� Dequeue�� ��������. ���� ������Ű� ������ ť���� �����Ͱ� �׿� �޸� ���� �߻�
		// ������ ġ����Ű� ������ ���۽ð����� �ֹ��ð��� ��� ť���� ����ִ½ð��� ����
		if (makeProc <= 0 && !QIsEmpty(&queue)) 
		{
			makeProc = Dequeue(&queue);
		}
		makeProc--;
	}

	printf_s("�ùķ��̼� ����\n");
	printf_s("ġ�� ���� : %d \n", cheOrder);
	printf_s("�Ұ�� ���� : %d \n", bulOder);
	printf_s("���� ���� : %d \n", dubOrder);
	printf_s("��� �� ������ : %d\n", QUEUE_LEN);


}