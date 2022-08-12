#pragma once
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;
public:
	bool InitMembers(const Point& ul, const Point& lr);
	bool InitMembers(const Point* ul, const Point* lr);
	void ShowRecInfo() const;
	//������ �ɹ� �̴ϼȶ������� �̿��� �ɹ��ʱ�ȭ
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
};


#endif // !__RECTANGLE_H__



