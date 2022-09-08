#ifndef __TEST1_H__
#define __TEST1_H__

#include <iostream>
using namespace std;

#pragma once
class test1
{
private:
	int xpos, ypos;
public:
	test1(int x = 0, int y = 0);
	void show();
	void SetPos(int x, int y);
	friend ostream& operator<<(ostream& os, const test1& pos);
};

#endif // !__TEST1_H__