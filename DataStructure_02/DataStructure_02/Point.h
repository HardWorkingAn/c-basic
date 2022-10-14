#pragma once
typedef struct _Point
{
	int x;
	int y;
}Point;

void ShowPoint(Point* point);
void SetPoint(Point* point, int xpos, int ypos);
int PointComp(Point* pos1, Point* pos2);
