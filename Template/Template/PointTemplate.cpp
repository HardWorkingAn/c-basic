#include <iostream>
#include "PointTemplate.h"
using namespace std;


template<typename T>
PointTemplate<T>::PointTemplate(T x, T y) : xpos(x), ypos(y)
{ }

template<typename T>
void PointTemplate<T>::ShowPosition() const
{
	cout << '[' << xpos << " ," << ypos << ']' << endl;
}