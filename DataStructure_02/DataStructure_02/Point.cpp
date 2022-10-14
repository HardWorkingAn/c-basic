#include <iostream>
#include "Point.h"



void ShowPoint(Point* point)
{
	printf("[%d, %d]\n", point->x, point->y);
}

void SetPoint(Point* point, int xpos, int ypos)
{
	point->x = xpos;
	point->y = ypos;
}

int PointComp(Point* pos1, Point* pos2)
{
	if (pos1->x == pos2->x && pos1->y == pos2->y)
		return 0;
	else if (pos1->x == pos2->x)
		return 1;
	else if (pos1->y == pos2->y)
		return 2;
	else
		return -1;
}
