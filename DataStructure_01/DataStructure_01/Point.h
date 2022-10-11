#pragma once

typedef struct _Point
{
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point* ppos, int xpos, int ypos);

void ShowPointPos(Point* pos);

int PointComp(Point* pos1, Point* pos2);