#include "Point.h"
#include <iostream>
using namespace std;
bool Point::InitMembers(int xpos,int ypos) {
	if (xpos < 0 || ypos < 0) {
		std::cout << "범위에 벗어난 값 전달 " << std::endl;
		return false;
	}
	cout << xpos << ypos << endl;
	x = xpos;
	y = ypos;
	return true;
}
int Point::GetX() const { return x; }
int Point::GetY() const { return y; }
bool Point::SetX(int xpos) {
	if (0 > xpos || xpos > 100) {
		std::cout << "벗어난 범위의 값 전달" << std::endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos) {
	if (0 > ypos || ypos > 100) {
		std::cout << "벗어난 범위의 값 전달" << std::endl;
		return false;
	}
	y = ypos;
	return true;
}
//생성자 맴버 이니셜라이저를 이용한 맴버초기화
Point::Point(const int& xpos, const int& ypos)
	:x(xpos),y(ypos)
{

}