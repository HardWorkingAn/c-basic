#include <iostream>
using namespace std;

//상속
/*
class Person
{
private:
    int age;
    char name[50];
    char* name2;
public:  
    Person() : age(20)
    {
        strcpy(name, "TEST");
        name2 = new char[50]; // 오류방지용
    }
    Person(const char* myname) : age(20)
    {
        strcpy(name, "TEST");
        name2 = new char[(strlen(myname) + 1)];
        strcpy(name2, myname);
    }
    Person(int age, const char* myname) : age(age)
    {
        strcpy(name, myname);
        name2 = new char[(strlen(myname) + 1)];
        strcpy(name2, myname);
    }
    void WhatYourName() const
    {
        cout << "내 이름은 : " << name << endl;
    }
    void HowOldAreYou() const
    {
        cout << "내 나이는 : " << age << endl;
    }
    ~Person()
    {
        cout << "~Person : " << age << ", " << name << endl;
        cout << "delete char* name2" << endl;
        delete[] name2;
    }
};
class UnivStudent : public Person // Person클래스를 상속받음
{
private:
    char major[50]; //전공과목
    char* major2;
    //Person을 상속받으니 Person의 name과 age가 있다.
public:
    UnivStudent()
    {
        cout << "UnivStudnet()" << endl;
        strcpy(major, "TEST_MAJOR");
        major2 = new char[50];//오류방지
    }
    UnivStudent(const char* mymajor)
    {
        cout << "UnivStudnet(const char* major)" << endl;
        strcpy(major, mymajor);
        major2 = new char[strlen(mymajor) + 1];
        strcpy(major2, mymajor);
    }
    UnivStudent(const char* myname, int myage, const char* mymajor) : Person(myage, myname)
    {
        cout << "UnivStudnet(const char* myname, int myage, const char* mymajor)" << endl;
        strcpy(major, mymajor);
        major2 = new char[strlen(mymajor) + 1];
        strcpy(major2, mymajor);
    }

    ~UnivStudent()
    {
        cout << "~UnivStudent : " << major << endl;
        cout << "delete char* major2" << endl;
        delete[] major2;
    }
    void WhoAreYou() {
        //WhatYourName과 HowOldAreYou는 Person을 상속받았기 때문에 접근이 가능하다.
        WhatYourName();
        HowOldAreYou();
        cout << "내 전공은 : " << major << endl;
    }
};
*/
//문제 07-1 1번 295p
/*
class car
{
private:
    int gasolineGauge;
public:
    car(int gas) : gasolineGauge(gas) { }
    void ShowGas() {
        cout << "잔여 가솔린 : " << gasolineGauge << endl;
    }
};
class HybridCar : public car
{
private:
    int electricGauge;
public:
    HybridCar(int gas,int electric) : car(gas), electricGauge(electric) { }
    void ShowElectric()
    {
        ShowGas();
        cout << "잔여 전기량 : " << electricGauge << endl;
    }
};
class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec),waterGauge(water){ }
    void ShowGauge() {
        ShowElectric();
        cout << "잔여 워터량 : " << waterGauge << endl;
    }
};
*/
//문제 07-1 2번 296p
/*
class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(const char* myname, int age) : age(age)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~MyFriendInfo()
    {
        cout << "delete[] name : " << name << endl;
        delete[] name;
        cout << "MyFriendInfo" << endl;
    }
};
class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* myname, int age, const char* addr_, const char* phone_) :MyFriendInfo(myname, age)
    {
        addr = new char[strlen(addr_) + 1];
        phone = new char[strlen(phone_) + 1];
        strcpy(addr, addr_);
        strcpy(phone, phone_);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소 : " << addr << endl;
        cout << "전화 : " << phone << endl;
    }
    ~MyFriendDetailInfo()
    {
        cout << "delete[] addr : " << addr << endl;
        delete[] addr;
        cout << "delete[] phone : " << phone << endl;
        delete[] phone;
        cout << "MyFriendDetailInfo"<< endl;
    }
};
*/
//상속 접근형태
/*
class Base
{
private: 
    int num1; //해당 클래스에서만 사용가능
protected:
    int num2; //상속받은 유도클래스에서도 사용가능
public:
    int num3; //상속받은 유도클래스 뿐만 아니라 메인에서도 참조 및 수정가능
    void ShowData()
    {
        cout << num1 << ", " << num2 << ", " << num3 << endl;
    }
};

class Derived : protected Base
{
// private num1 //접근불가능
// protected num2 //기본 protected 형태
// protected num3 //protected 형태로 상속받았기 떄문에 num3는 protected 형태로 변환
};
//public 상속은 private를 제외한 나머지는 그대로(protected는 protected형태로) 상속 된다.
*/
//상속의 하기 위한 최소한의 조건은 IS-A(일종의 ~)관계 ex) 컴퓨터 - 노트북 노트북은 컴퓨터의 일종
//기존의 기능을 가지고가면서 새로운 기능을 추가할 때 상속받아 기능을 추가한다.
/*
//IS-A 관계
class computer 
{
private:
    char owner[50];
public:
    computer(const char* name) 
    {
        strcpy(owner, name);
    }
    void calculator() {
        cout << "내용을 계산합니다." << endl;
    }
};
class notebook : public computer
{
private:
    int battery;
public:
    notebook(const char* name, int batteryGauge) : computer(name),battery(batteryGauge)
    {
    }
    void charging() 
    {
        battery += 5;
    }
    void useBattery()
    {
        battery -= 1;
    }
    int GetBattery() { return battery; }
    void movingCal()
    {
        if (GetBattery() < 1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        cout << "이동 하면서 ";
        calculator();
        useBattery();
    }
};
class tabletNotebook : public notebook
{
private:
    char penModel[50];
public:
    tabletNotebook(const char* name, int batteryGauge, const char* model) : notebook(name, batteryGauge)
    {
        strcpy(penModel, model);
    }
    void Write(const char* modelInfo)
    {
        if (GetBattery() < 1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        if (strcmp(modelInfo, penModel) != 0)
        {
            cout << "등륵된 펜이 아닙니다." << endl;
            return;
        }
        cout << "필기 내용을 처리합니다." << endl;
        useBattery();

    }
};
//HAS-A(~을 가진) 관계

class Gun
{
private:
    int bullet; // 총알갯수
public:
    Gun(int num) : bullet(num){}
    void Shot()
    {
        cout << "BBANG" << endl;
        bullet--;
    }
};

//class Police : public Gun
//{
//private:
//    int handcuffs; // 수갑의 갯수
//public:
//    Police(int num1, int num2) : Gun(num1), handcuffs(num2){}
//    void PutHandcuff()
//    {
//        cout << "잡았다" << endl;
//        handcuffs--;
//    }
//};

// Gun을 상속받을 경우 Police는 총을 안가지고 있다는 상황이 없다. 이를 해결하고자 한다.
// 상속관계는 강한 연관성이 띈다. 경우에 따라선 HAS-A관계도 사용 될 수 있으나 프로그램 변경에 많은 제약을 줄수 있다.
class Police
{
private:
    int handcuffs;
    Gun* pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void Shot()
    {
        if (pistol == NULL)
            cout << "총을 가지고 있지 않습니다." << endl;
        else
            pistol->Shot();
    }
    void PutHandcuff()
            {
                cout << "잡았다" << endl;
                handcuffs--;
            }
    ~Police()
    {
        if (pistol != NULL)
        {
            delete pistol;
        }
    }
};
*/
//문제 07-2 1번 IS-A 관계 상속
/*
class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(int wid, int hei) : width(wid), height(hei)
    {
    }
    void showArea()
    {
        cout << "면적 : " << width * height << endl;
    }

};
class square : public Rectangle
{
public:
    square(int num) : Rectangle(num, num) {}
};
*/
//문제 07-2 2번
class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* book_title, const char* book_isbn, int book_price) : price(book_price)
    {
        title = new char[(strlen(book_title) + 1)];
        isbn = new char[(strlen(book_isbn) + 1)];
        strcpy(title, book_title);
        strcpy(isbn, book_isbn);
    }
    void ShowBookInfo()
    {
        cout << "제목 : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "가격 : " << price << endl;
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
};
class EBook : public Book
{
private:
    char* DRMkey;
public:
    EBook(const char* book_title, const char* book_isbn, int book_price, const char* key) : Book(book_title, book_isbn, book_price)
    {
        DRMkey = new char[strlen(key) + 1];
        strcpy(DRMkey, key);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키 : " << DRMkey << endl;
    }
    ~EBook()
    {
        delete[] DRMkey;
    }
};


int main()
{
    /*
    UnivStudent student1("KIM", 23, "computer");
    student1.WhoAreYou();
    cout << "----------------------------------" << endl;
    UnivStudent student2;
    student2.WhoAreYou();
    cout << "----------------------------------" << endl;
    UnivStudent student3("GOOGLE");
    student3.WhoAreYou();
    */
    //문제 07-1 1번 295p
    /*
    HybridWaterCar car(50, 60, 70);
    car.ShowGauge();
    */
    //문제 07-1 2번 296p
    /*
    MyFriendDetailInfo fri("KIM", 12, "AAABBBCCC", "010-1122-3456");
    fri.ShowMyFriendDetailInfo();
    */
    //상속 접근형태
    /*
    Base a;
    a.num3 = 10;
    Derived b;
    //b.num3 = 10; // protected로 상속받았기 떄문에 num3는 public이 아닌 protected형태이다.
    */
    //상속의 조건과 관계모델
    //IS-A 관계
    /*
    notebook nb("KIM", 5);
    tabletNotebook tb("AN", 2, "ISE");
    nb.movingCal();
    tb.Write("ISE");
    tb.Write("SSS");
    cout << "nb battery : " << nb.GetBattery() << endl;
    cout << "tb battery : " << tb.GetBattery() << endl;
    tb.Write("ISE");
    tb.Write("SSS");
    
    //HAS-A 관계
    
    //Police pman(5, 3);
    //pman.Shot();
    //pman.PutHandcuff();

    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();
    
    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();
    */
    //문제 07-2 1번 IS-A 관계 상속
    /*
    Rectangle rec(4, 3);
    rec.showArea();

    square sqr(7);
    sqr.showArea();
    */
    //문제 07-2 2번
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("좋은 C++", "555-12345-890-1", 10000, "fagqw2315t1g");
    ebook.ShowEBookInfo();

    std::cout << "\nEnd Of Main\n";
}
