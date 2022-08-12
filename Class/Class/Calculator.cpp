#ifndef __CALCULATOR_H__;
#define __CALCULATOR_H__

#include "Calculator.h"
#include <iostream>
void Calculator::Init() {
	for (int i = 0; i != sizeof(cal_sum) / sizeof(cal_sum[0]); i++) {
		cal_sum[i] = 0;
	}
};
double Calculator::Add(const double& x, const double& y) {
	cal_sum[0] += 1;
	return x + y;
}
double Calculator::Min(const double& x, const double& y) {
	cal_sum[1] += 1;
	return x - y;
}
double Calculator::Mul(const double& x, const double& y) {
	cal_sum[2] += 1;
	return x * y;
}
double Calculator::Div(const double& x, const double& y) {
	cal_sum[3] += 1;
	return x / y;
}
void Calculator::ShowOpCount() {
	printf("µ¡¼À: %d »¬¼À: %d °ö¼À: %d ³ª´°¼À: %d \n",cal_sum[0], cal_sum[1], cal_sum[2], cal_sum[3]);
}
#endif // !__CALCULATOR_H__;



