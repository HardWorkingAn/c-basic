#pragma once
#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

#include <iostream>
#include "test1.h"
using namespace std;


template<typename T>
class SmartPtr
{
private:
	T* Tptr;
public:
	SmartPtr(T* ptr) : Tptr(ptr) {}
	T& operator*() const { return *Tptr; }
	T* operator->() const { return Tptr; }
	~SmartPtr() { delete Tptr; }
};
#endif // !__SMARTPOINTER_H__
