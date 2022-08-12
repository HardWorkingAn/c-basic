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
	cout << "�̸� : " << Name << endl;
	cout << "ȸ�� : " << CompName << endl;
	cout << "��ȭ��ȣ : " << PhoneNum << endl;
	switch (Posision)
	{
	case COMP_POS::CLERK:
		cout << "����  : ���" << endl;
		break;
	case COMP_POS::SENIOR:
		cout << "����  : ����" << endl;
		break;
	case COMP_POS::ASSIST:
		cout << "����  : �븮" << endl;
		break;
	case COMP_POS::MANAGER:
		cout << "����  : ����" << endl;
		break;
	default:
		cout << Posision << endl;
		break;
	}
}
NameCard::~NameCard() {
	cout << Name << "�Ҹ���" << endl;
	delete[] Name;
	delete[] CompName;
	delete[] PhoneNum;
}
#endif // !__NAMECARD_H__


