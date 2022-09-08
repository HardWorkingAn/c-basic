#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include <iostream>
using namespace std;

template<typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray&) {};
	BoundCheckArray operator=(const BoundCheckArray&) {};
public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new T[arrlen];
}

template<typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "배열 범위에 벗어남" << endl;
		exit(1);
	}
	return arr[idx];
}
template<typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "배열 범위에 벗어남" << endl;
		exit(1);
	}
	return arr[idx];
}
template<typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}
template<typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}
#endif