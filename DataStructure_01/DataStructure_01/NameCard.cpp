#include <iostream>
#include "NameCard.h"


NameCard* MakeNameCard(const char* name, const char* phone)
{
	NameCard* pCard = new NameCard();

	strcpy(pCard->name, name);
	strcpy(pCard->phone, phone);

	return pCard;
}

void ShowNameCardInfo(NameCard* Card)
{
	printf("�̸� : %s\n", Card->name);
	printf("��ȣ : %s\n", Card->phone);
}

int NameCompare(NameCard* pCard, const char* name)
{
	int check;

	check = strcmp(pCard->name, name);

	return check;
}

void ChangePhoneNum(NameCard* pCard, const char* phone)
{
	strcpy(pCard->phone, phone);
}
