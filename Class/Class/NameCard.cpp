#ifndef __NAMECARD_H__
#define __NAMECARD_H__
#include "NameCard.h"
#include <iostream>
#include <cstring>
using namespace std;

NameCard::NameCard(const char* name, const char* compName, const char* phoneNum, int posision)
	:NameCard::Posision(posision)
{
	Name = new char[strlen(name) + 1];
	CompName = new char[strlen(compName) + 1];
	PhoneNum = new char[strlen(phoneNum) + 1];

	strcpy(Name, name);
	strcpy(CompName, compName);
	strcpy(PhoneNum, phoneNum);
	
	
}
void NameCard::ShowNameCardInfo() {
	cout << "이름 : " << Name << endl;
	cout << "회사 : " << CompName << endl;
	cout << "전화번호 : " << PhoneNum << endl;
	switch (Posision)
	{
	case COMP_POS::CLERK:
		cout << "직급  : 사원" << endl;
		break;
	case COMP_POS::SENIOR:
		cout << "직급  : 주임" << endl;
		break;
	case COMP_POS::ASSIST:
		cout << "직급  : 대리" << endl;
		break;
	case COMP_POS::MANAGER:
		cout << "직급  : 과장" << endl;
		break;
	default:
		cout << Posision << endl;
		break;
	}
}
NameCard::~NameCard() {
	cout << Name << "소멸자" << endl;
	delete[] Name;
	delete[] CompName;
	delete[] PhoneNum;
}
#endif // !__NAMECARD_H__


