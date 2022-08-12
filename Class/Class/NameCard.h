#pragma once
namespace COMP_POS
{
	enum{
		CLERK, SENIOR, ASSIST, MANAGER
	};
};
class NameCard
{
	
private:
	
	char* Name;
	char* CompName;
	char* PhoneNum;
	int Posision;
public:
	NameCard(const char* Name, const char* CompName, const char* PhoneNum, int posision);
	void ShowNameCardInfo();
	~NameCard();
	
};

