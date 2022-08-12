#pragma once
#ifndef __POINT_H__
#define __POINT_H__
class Point
{
private:
	int x;
	int y;
public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
	//생성자 맴버 이니셜라이저를 이용한 맴버초기화
	Point(const int& xpos, const int& ypos);
};

#endif


