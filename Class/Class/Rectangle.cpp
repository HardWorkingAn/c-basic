#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) {
		cout << "잘못된 위치 정보 전달" << endl;
		return false;
	}
	upLeft = ul;
	lowRight = lr;
	return true;
}
bool Rectangle::InitMembers(const Point* ul, const Point* lr) {
	if (ul->GetX() > lr->GetX() || ul->GetY() > lr->GetY()) {
		cout << "잘못된 위치 정보 전달" << endl;
		return false;
	}

	upLeft = *ul;
	lowRight = *lr;
	return true;
}
void Rectangle::ShowRecInfo() const{
	cout << "좌 상단 : " << '[' << upLeft.GetX() << ", " << upLeft.GetY() << ']' << endl;
	cout << "우 하단 : " << '[' << lowRight.GetX() << ", " << lowRight.GetY() << ']' << endl;
}
//생성자 맴버 이니셜라이저를 이용한 맴버초기화
Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	:upLeft(x1, y1), lowRight(x2, y2)
{

}