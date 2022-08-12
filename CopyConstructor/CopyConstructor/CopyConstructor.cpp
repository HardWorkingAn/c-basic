#include <iostream>
using namespace std;

//복사생성자
/*
class SoSimple{
private:
    int num1, num2;
public:
    SoSimple(int num1, int num2) 
        : num1(num1), num2(num2)
    {
        cout << "기본 생성자" << endl;
    }
    // sim2 = sim1 을 하게 된다면 묵시적으로 sim2(sim1)으로 변환해주는데 explicit 키워드를 넣게되면 묵시적 변화를 막을 수있다.
    explicit SoSimple(SoSimple& copy)
        :num1(copy.num1), num2(copy.num2)
    {
        cout << "복사 생성자" << endl;
    }
    void ShowNum() {
        cout << num1 << ", " << num2 << endl;
    }
};
*/
//복사생성자 문제점
/*
class Person {
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
    //깊은 복사
    Person(const Person& copy)
        :age(copy.age)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    ~Person() {
        delete[] name;
        cout << "called destructor" << endl;
    }
    void ShowInfo() const
    {
        cout << "이름 : " << name;
        cout << ", 나이 : " << age << endl;
    }
};
*/
//복사생성자와 임시객체
/*
class Simple {
private:
    int num;
public:
    Simple(int num)
        : num(num)
    {
        cout << "기본 생성자" << endl;
    }
    
    Simple(Simple& copy)
        :num(copy.num)
    {
        cout << "복사 생성자" << endl;
    }
    Simple& AddNum(int n) {
        num += n;
        return *this;
    }
    void ShowNum() {
        cout << num << endl;
    }
    ~Simple() {
        cout << "생성자 소멸" << endl;
    }
};
Simple SimpleFuncObj(Simple ob) {
    //ob.ShowNum();
    cout << "return 이전" << endl;
    //ob 객체를 return 하면서 임시객체의 복사 생성자 호출
    return ob;
}
*/
//임시객체 소멸시기
/*
class Temporary {
private:
    int num;
public:
    Temporary(int n) :num(n) {
        cout << "create obj : " << num << endl;
    }
    ~Temporary() {
        cout << "destroy obj : " << num << endl;
    }
    void ShowTempInfo() {
        cout << "My num is " << num << endl;
    }
};
*/
class SoSimple{
private:
    int num;
public:
    SoSimple(int n) : num(n) {
        cout << " New Object : " << this << endl;
    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << " New Copy Obj : " << this << endl;
    }
    ~SoSimple() {
        cout << " Destroy Obj : " << this << endl;
    }
};
SoSimple SimpleFuncObj(SoSimple ob) {
    cout << " Parm ADR : " << &ob << endl;
    return ob;
}
int main()
{
    //복사생성자
    /*
    SoSimple sim1(10, 20);
    sim1.ShowNum();
    //SoSimple sim2 = sim1; // sim2 = sim1 을 하게 된다면 묵시적으로 sim2(sim1)으로 변환해주는데 explicit 키워드를 넣게되면 묵시적 변화를 막을 수있다.
    //sim2.ShowNum();
    SoSimple sim3(sim1);
    sim3.ShowNum();
    */
    //복사생성자 문제점 에러발생
    /*
    //man1의 name에는 문자열을 가지고있는 주소값을 가지고있고  man2 복사를 하면서 man2의 name에도 그 값을 가지고있다.
    //하지만 man2의 소멸자에서 name 포인터의 메모리 할당해제 delete를 하고 man1에서 delete 하게된다면 name은 이미 할당 해제된 상태인데 
    //메모리 할당해제 하려고 하기 때문에 오류가 발생한다.
    //하지만 Person(const Person& copy) 같은 깊은 복사를 정의해 놓으면 에러가 발생하지 않는다.
    Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowInfo();
    man2.ShowInfo();
    */
    //복사생성자와 임시객체
    /*
    Simple obj(7);
    cout << "함수 호출 전" << endl;
    // 해당 함수를 가르키는 변수명이 없어서 따로 찾지 못하지만 어딘가에 저장되어서 깊은복사를 사용하였으므로 서로 num을 가르키는 위치가 다르다.
    // obj 매개변수를 전달하면서 ob 객체 복사생성자 호출
    SimpleFuncObj(obj).AddNum(30).ShowNum();
    obj.ShowNum();
    cout << "함수 호출 후" << endl;
    */
    //임시객체 소멸시기
    /*
    Temporary(100);
    cout << "*********************************************" << endl << endl;

    Temporary(200).ShowTempInfo();
    cout << "*********************************************" << endl << endl;
    // 변수명이 있는 곳에 반환받았기 떄문에 임시객체가 아닌 객체라서 작동이 끝나고 소멸한다.
    const Temporary& ref = Temporary(300);
    cout << "*********************************************" << endl << endl;
    */
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout << endl;
    SoSimple tempRef = SimpleFuncObj(obj);
    cout << " Return Obj : " << &tempRef << endl;

    std::cout << "\nEnd of Main \n";
}