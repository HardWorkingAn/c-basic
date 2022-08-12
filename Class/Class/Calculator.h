#pragma once
class Calculator
{
private:
	int cal_sum[4];
public:
	void Init();
	double Add(const double& x, const double& y);
	double Min(const double& x, const double& y);
	double Mul(const double& x, const double& y);
	double Div(const double& x, const double& y);
	void ShowOpCount();
};

