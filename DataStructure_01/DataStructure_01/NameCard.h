#pragma once


#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// NameCard 구조체 변수의 할당 및 초기화 후 주소 값 변환
NameCard* MakeNameCard(const char* name,const char* phone);

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard* pCard);

// 이름이 같으면 0, 다르면 0이 아닌 값 변환
int NameCompare(NameCard* pCard,const char* name);

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard* pCard,const char* phone);
