#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) {
		cout << "�߸��� ��ġ ���� ����" << endl;
		return false;
	}
	upLeft = ul;
	lowRight = lr;
	return true;
}
bool Rectangle::InitMembers(const Point* ul, const Point* lr) {
	if (ul->GetX() > lr->GetX() || ul->GetY() > lr->GetY()) {
		cout << "�߸��� ��ġ ���� ����" << endl;
		return false;
	}

	upLeft = *ul;
	lowRight = *lr;
	return true;
}
void Rectangle::ShowRecInfo() const{
	cout << "�� ��� : " << '[' << upLeft.GetX() << ", " << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ� : " << '[' << lowRight.GetX() << ", " << lowRight.GetY() << ']' << endl;
}
//������ �ɹ� �̴ϼȶ������� �̿��� �ɹ��ʱ�ȭ
Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	:upLeft(x1, y1), lowRight(x2, y2)
{

}