#pragma once
#ifndef __CARINLINE_H__
#define __CARINLINE_H__

#include <iostream>

//파일분할
namespace CAR_CONST {
    enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
    };
}
using namespace std;

class Car {
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};
// inline 이 있으면 컴파일 과정에서 main에 삽입이 되는데 기본의 h파일이 선언되기전 cpp 파일에서 헤더파일을 호출을 하기 떄문에 오류가 발생
// 그렇기 때문에 inline 함수를 쓸려면 해더파일 안에 선언과 정의를 같이 해줘야한다.
// inline이 필요 없는 부분은 굳이 헤더파일에서 쓸 필요없고 따로 cpp 파일 만들어서 정의해줘도 된다.
inline void Car::ShowCarState() {
    cout << "소유자ID : " << gamerID << endl;
    cout << "연료량 : " << fuelGauge << "%" << endl;
    cout << "현재속도 : " << curSpeed << "km/s\n" << endl;
}

inline void Car::Break() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}
#endif // !