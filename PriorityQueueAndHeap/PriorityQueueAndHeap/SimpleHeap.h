#pragma once

#define TRUE     1
#define FALSE	 0

#define HEAP_LEN 100


//typedef char HData;
typedef const char* HData;
//typedef int Proiority; // 우선순위
typedef int PriorityComp(HData d1, HData d2);


//typedef struct _heapElem
//{
//	Proiority pr;
//	HData data;
//} HeapElem;

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	//HeapElem heapArr[HEAP_LEN];
	HData heapArr[HEAP_LEN];
}Heap;

//void HeapInit(Heap* ph);
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

//void HInsert(Heap* ph, HData data, Proiority pr);
void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);