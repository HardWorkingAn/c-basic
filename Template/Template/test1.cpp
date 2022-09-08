#include <iostream>
#include "test1.h"
using namespace std;

test1::test1(int x, int y) : xpos(x), ypos(y){}

void test1::show() 
{
	cout << '[' << xpos << " ," << ypos << ']' << endl;
}

void test1::SetPos(int x, int y)
{
	xpos = x;
	ypos = y;
}

ostream& operator<<(ostream& os, const test1& pos)
{
	os << '[' << pos.xpos << " ," << pos.ypos << ']' << endl;
	return os;
}
