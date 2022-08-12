#include <iostream>
#include <cstring>
using namespace std;

//enum을 통해 구조체 안에 한번에 넣을 수 있다.
/*
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10
*/

//구조체
/*
typedef struct Test
{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
} CC;

struct Car
{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
};

void ShowCarState(const Car& car) {
    cout << "소유자ID : " << car.gamerID << endl;
    cout << "연료량 : " << car.fuelGauge << "%" << endl;
    cout << "현재속도 : " << car.curSpeed << "km/s\n" << endl;
}

void Accel(Car& car) {
    if (car.fuelGauge <= 0) {
        return;
    }
    else {
        car.fuelGauge -= CAR_CONST::FUEL_STEP;
    }

    if (car.curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
        car.curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    car.curSpeed += CAR_CONST::ACC_STEP;
}
void Break(Car& car) {
    if (car.curSpeed < CAR_CONST::BRK_STEP) {
        car.curSpeed = 0;
        return;
    }
    car.curSpeed -= CAR_CONST::BRK_STEP;
}
//name space 를 통해 범위 지정 연산자를 생략
using namespace CAR_CONST;
struct Car2
{
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState() {
        cout << "소유자ID : " << gamerID << endl;
        cout << "연료량 : " << fuelGauge << "%" << endl;
        cout << "현재속도 : " << curSpeed << "km/s\n" << endl;
    }

    void Accel() {
        if (fuelGauge <= 0) {
            return;
        }
        else {
            fuelGauge -= FUEL_STEP;
        }

        if (curSpeed + ACC_STEP >= MAX_SPD) {
            curSpeed = MAX_SPD;
            return;
        }
        curSpeed += ACC_STEP;
    }
    void Break();
    
    //void Break() {
    //    if (curSpeed < BRK_STEP) {
    //        curSpeed = 0;
    //        return;
    //    }
    //    curSpeed -= BRK_STEP;
    //}
    
};

//또한 범위 지정 연산자로 함수를 외부로 뺼 수 있다.
void Car2::Break() {
    if (curSpeed < BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= BRK_STEP;
}
*/
//문제 03-1 구조체 내에 함수정의 114p
/*
struct Point
{
    int xpos;
    int ypos;

    void MovePos(int x, int y) {
        xpos += x;
        ypos += y;
    }
    void AddPoint(const Point& pos) {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }
    void showPosition() {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};
*/
//클래스
/*
namespace CAR_CONST {
    enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
    };
}
class Car {
private:
    //CAR_CONST:: 는 using namespace CAR_CONST;를 사용하면 생략가능
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();

};
void Car::InitMembers(const char* ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}
void Car::ShowCarState() {
    cout << "소유자ID : " << gamerID << endl;
    cout << "연료량 : " << fuelGauge << "%" << endl;
    cout << "현재속도 : " << curSpeed << "km/s\n" << endl;
}

void Car::Accel() {
    if (fuelGauge <= 0) {
        return;
    }
    else {
        fuelGauge -= CAR_CONST::FUEL_STEP;
    }

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}
*/
//파일분할 (Car.cpp, Car.h) h에선 선언을 하고 cpp 에서는 정의를 하여 기능을 구현
//#include "Car.h"
//#include "CarInline.h"

//문제 03-2 1 클래서 정의 135p
//#include "Calculator.h"
//문제 03-2 2
//#include "Printer.h"
//객체지향 프로그래밍 이해 136p
/*
class FruitSeller {
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    void InitMembers(int price, int num, int money) {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int SaleApples(int money) {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult() {
        cout << "남은 사과 : " << numOfApples << endl;
        cout << "판매 수익 : " << myMoney << endl;
    }

};
class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money) {
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller& seller, int money) {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult() {
        cout << "현재 잔액 : " << myMoney << endl;
        cout << "사과 개수 : " << numOfApples << endl;
    }
};
*/
//객체지향 프로그래밍 이해 사각형 point 위치 파일분할 (rectangle, Point)
//#include "Rectangle.h"
//#include "Point.h"
//캡슐화
/*
class SinivelCap {
public:
    void Take() const { cout << "콧물이 싹 납니다." << endl; }
};
class SneezeCap {
public:
    void Take() const { cout << "재채기가 멎습니다." << endl; }
};
class SnuffleCap {
public:
    void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class ColdPatient {
public:
    void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); };
    void TakeSinivelCap(const SneezeCap& cap) const { cap.Take(); };
    void TakeSinivelCap(const SnuffleCap& cap) const { cap.Take(); };

};
*/
//문제 04-2 166p
/*
class Point {
private:
    int xpos, ypos;
public:
    void Init(int x, int y) {
        xpos = x;
        ypos = y;
    }
    void showPointInfo() {
        cout << "[ " << xpos << ", " << ypos << " ]" << endl;
    }
};
class Circle {
private:
    int radius;
    Point center;
public:
    void Init(int x, int y, int r) {
        radius = r;
        center.Init(x, y);
    }
    void showCircleInfo() {
        cout << "radius : " << radius << endl;
        center.showPointInfo();
    }
};
class Ring {
    Circle inCircle;
    Circle outCircle;
public:
    void Init(int inX, int inY, int inRad, int outX, int outY, int outRad) {
        inCircle.Init(inX, inY, inRad);
        outCircle.Init(outX, outY, outRad);
    }
    void showRingInfo() {
        cout << "Inner Circle Info" << endl;
        inCircle.showCircleInfo();
        cout << "Outter Circle Info" << endl;
        outCircle.showCircleInfo();
    }
};
*/
//생성자 객체 생성시 딱 한번 호출된다.
/*
class TestClass
{
private:
    int x, y;
public:
    
    //TestClass() {
    //    x = 0;
    //    y = 0;
    //    cout << "TestClass() 생성자" << endl;
    //}
    //TestClass(int x) {
    //    this->x = x;
    //    y = 0;
    //    cout << "TestClass(x) 생성자" << endl;
    //}
    //TestClass(int x = 10, int y = 30) {
    //    this->x = x;
    //    this->y = y;
    //    cout << "TestClass(x,y) 생성자" << endl;
    //}
    
    TestClass(int x = 1, int y = 3) {
        this->x = x;
        this->y = y;
        cout << "TestClass(x = n,y = m) 생성자" << endl;
    }
    void ShowDate() const {
        cout << x << ' ' << y << endl;
    }
    
};
TestClass tc4() {
    TestClass tc(20, 30);
    return tc;
}
*/
//생성자 이니라이저 이용한 맴버초기화 (파일재사용)
/*
#include "Rectangle.h"
#include "Point.h"
*/
//디폴트 생성자 및 private 생성자
/*
class AAA {
private:
    int num;
    AAA(int n) :num(n) {} // pravate 생성자
public:
    // 생성자를 안넣었다면 컴파일에서 실행할 때 자동적으로 AAA() {}가 넣어진다.
    //AAA(int n) : num(n) {}; // 만약 이처럼 생성자가 매게변수가 있다면 변수를 생성할 때 AAA a;를 하게된다면 생성자 불일치가 일어난다.
    AAA() : num(0) {}; // 이렇게 만들면 AAA a;로 바로 변수를 생성할 수 있다.
    int GetNum(){ return num; }

    AAA& createInitObj(int n) const {
        AAA* ptr = new AAA(n); //create 함수를 이용하여 pravate의 생성자 호출
        return *ptr;
    }
    void showNum() {
        cout << num << endl;
    }

};
*/
//소멸자
/*
class Person {
private:
    char* name;
    int age;
public:
    Person(const char* myName, int myAge) {
        int len = strlen(myName) + 1;
        name = new char[len];
        strcpy(name, myName);
        age = myAge;
        cout << myName << " 생성자 생성\n";
    }
    void showPersonInfo() {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~Person() {
        cout << name << " 소멸자 생성\n";
        delete[] name;
        
    }
};
*/
//문제 04-3 190p 파일분리 동적할당, enum, class
//#include "NameCard.h"
// 클래스 배열 및 동적할당
/*
class Person{
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage) 
        :age(myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        cout << "called Person(myname, myage)" << endl;
    }
    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    ~Person() {
        cout << "called destructor" << endl;
        delete []name;
    }
    void SetPersonInfo(const char* myname, int myage) 
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
        age = myage;
    }
    void ShowInfo() const 
    {
        cout << "이름 : " << name;
        cout << ", 나이 : " << age << endl;
    }    
};
*/
//this 포인터
class SoSimple {
private:
    int num;
public:
    SoSimple(int n)
        :num(n)
    {
        cout << "num = " << num << " ";
        cout << "address = " << this << endl;
    }
    void ShowSimpleData()
    {
        cout << num << endl;
        
    }
    SoSimple* GetThisPointer() {
        return this;
    }
};
class TwoNumber {
private:
    int num1, num2;
public:
    TwoNumber(int num1, int num2) {
        this->num1 = num1;
        this->num2 = num2;
    }
    //TwoNumber(int num1, int num2)
    //    : num1(num1), num2(num2)
    //{
    //}
    void ShowTwoNumber() {
        cout << this->num1 << endl;
        cout << this->num2 << endl;
    }
};
class SelfRef {
private:
    int num;
public:
    SelfRef(int n) : num(n) {
        cout << "객체생성" << endl;
    }
    SelfRef& Addr(int n) {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumber(){
        cout << num << endl;
        return *this;
    }
};
int main()
{
    //구조체
    /*
    CC* a = new CC;
    Car run99 = { "run99", 100, 0 };
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    Break(run99);
    ShowCarState(run99);

    Car sped77 = { "sped77", 100, 0 };
    Accel(sped77);
    Break(sped77);
    ShowCarState(sped77);
    
    Car2 test1 = { "test1", 80, 0 };
    test1.Accel();
    test1.ShowCarState();
    test1.Break();
    test1.ShowCarState();
    */
    //문제 03-1 구조체 내에 함수정의 114p
    /*
    Point pos1 = { 12, 4 };
    Point pos2 = { 20, 30 };

    pos1.MovePos(-7, 10);
    pos1.showPosition();

    pos1.AddPoint(pos2);
    pos1.showPosition();
    */
    //클래스 134줄 and 파일분할 (Car.cpp, Car.h) h에선 선언을 하고 cpp 에서는 정의를 하여 기능을 구현
    /*
    Car car;
    // & 참조자는 배열을 사용할 수 없다.
    car.InitMembers("car", 100);
    car.Accel();
    car.Accel();
    car.Accel();
    car.ShowCarState();
    car.Break();
    car.ShowCarState();

    Car* car2 = new Car;
    car2->InitMembers("car2", 50);
    car2->Accel();
    car2->Accel();
    car2->Accel();
    car2->ShowCarState();
    car2->Break();
    car2->ShowCarState();
    */
    //문제 03-2 1 클래서 정의 135p
    /*
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4  = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7  = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5  = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2  = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    */
    //문제 03-2 2
    /*
    Printer* str1 = new Printer;
    Printer str2;

    str1->SetString("hello google");
    str1->ShowString();
    str1->SetString("I HATE C++");
    str1->ShowString();

    str2.SetString("str2 print");
    str2.ShowString();
    str2.SetString("str2 change");
    str2.ShowString();
    */
    //객체지향 프로그래밍 이해 136p
    /*
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "seller" << endl;
    seller.ShowSalesResult();
    cout << "buyer" << endl;
    buyer.ShowBuyResult();
    */
    /*
    Point pos1;
    if (!pos1.InitMembers(-2, 4)) {
        cout << "초기화 실패" << endl;
    }
    if (!pos1.InitMembers(2, 4)) {
        cout << "초기화 실패" << endl;
    }
    Point pos2;
    if (!pos2.InitMembers(5, 9)) {
        cout << "초기화 실패" << endl;
    }
    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1)) {
        cout << "직사각형 초기화 실패" << endl;
    }
    if (!rec.InitMembers(pos1, pos2)) {
        cout << "직사각형 초기화 실패" << endl;
    }
    rec.ShowRecInfo();

    cout << "\n힙메모리 new 키워드\n" << endl;
    Point* pos3 = new Point;
    if (!pos3->InitMembers(-2, 4)) {
        cout << "초기화 실패" << endl;
    }
    if (!pos3->InitMembers(7, 10)) {
        cout << "초기화 실패" << endl;
    }
    Point* pos4 = new Point;
    if (!pos4->InitMembers(22, 30)) {
        cout << "초기화 실패" << endl;
    }
    Rectangle* rec2 = new Rectangle;
    if (!rec2->InitMembers(pos4, pos3)) {
        cout << "직사각형 초기화 실패" << endl;
    }
    if (!rec2->InitMembers(pos3, pos4)) {
        cout << "직사각형 초기화 실패" << endl;
    }
    rec2->ShowRecInfo();

    delete pos3, pos4, rec2;
    */
    //캡슐화
    /*
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;

    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSinivelCap(zcap);
    sufferer.TakeSinivelCap(ncap);
    */
    //문제 04-2 166p
    /*
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.showRingInfo();
    */
    //생성자 객체 생성시 딱 한번 호출된다.
    /*
    TestClass tc1;
    tc1.ShowDate();

    TestClass tc2(10);
    tc2.ShowDate();

    TestClass* tc3 = new TestClass(30, 40);
    tc3->ShowDate();

    TestClass tc4();
    TestClass myTc = tc4();
    myTc.ShowDate();
    */
    //생성자 이니라이저 이용한 맴버초기화 (파일재사용)
    /*
    Rectangle rect(1,1,5,5);
    rect.ShowRecInfo();
    */
    //디폴트 생성자 및 private 생성자
    /*
    AAA a;
    a.showNum();

    AAA& b = a.createInitObj(3);
    b.showNum();

    AAA& c = a.createInitObj(12);
    c.showNum();

    a.showNum();
    */
    //소멸자
    /*
    Person man1("Lee dong woo", 29);
    Person man2("Jang dong gun", 41);
    man1.showPersonInfo();
    man2.showPersonInfo();
    */
    //문제 04-3 190p 파일분리 동적할당, enum, class
    /*
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard ManAssit("Kim", "soGoodComp", "010-5555-5555", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    ManAssit.ShowNameCardInfo();
    */
    // 클래스 배열 및 동적할당
    /*
    //Person parr[3];
    Person* parrptr[3];
    char namestr[100];
    char* strptr;
    int age;
    int len;

    for (int i = 0; i < 3; i++) {
        cout << "이름 : ";
        cin >> namestr;
        cout << "나이 : ";
        cin >> age;
        
        //len = strlen(namestr) + 1;
        //strptr = new char[len];
        //strcpy(strptr, namestr);
        //parr[i].SetPersonInfo(strptr, age);
        
        parrptr[i] = new Person(namestr, age);
    }
    parrptr[0]->ShowInfo();
    parrptr[1]->ShowInfo();
    parrptr[2]->ShowInfo();
    //parr[0].ShowInfo();
    //parr[1].ShowInfo();
    //parr[2].ShowInfo();
  */  
    //this 포인터
    SoSimple sim1(100);
    SoSimple* ptr1 = sim1.GetThisPointer(); // sim1 객체 이용
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple* ptr2 = sim1.GetThisPointer(); // sim1 객체 이용
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();

    SoSimple* sim3 = new SoSimple(300);
    cout << sim3 << ", ";
    sim3->ShowSimpleData();

    TwoNumber two(2, 4);
    two.ShowTwoNumber();

    SelfRef obj(3);
    SelfRef& ref = obj.Addr(2); // addr 에서 obj의 num 3에서 2값을 더하고 주소값을 ref에 저장 obj == ref

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    // Addr 과 ShowTwo에서 *this를 통해 자기 자신의 주소값을 반환받기 때문에 이어서 가능한 문장
    ref.Addr(1).ShowTwoNumber().Addr(2).ShowTwoNumber(); 

    cout << "\nend of main \n";
}

