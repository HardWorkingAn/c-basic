#include <iostream>
using namespace std;

//구조체로 클래스 따라하기
typedef struct Data {
    int data;
    void (*ShowData)(Data*);
    void (*Add)(Data*, int);
} Data;
void ShowData(Data* data_) {
    cout << data_->data << endl;
}
void Add(Data* data_, int num)
{
    data_->data += num;
}
//가상상속

class Base
{
public:
    Base()
    {
        cout << "Basce 생성자" << endl;
    }
    void SimpleFunc()
    {
        cout << "BaseOne" << endl;
    }
};
class MiddleOne : virtual public Base
{
public:
    MiddleOne() : Base()
    {
        cout << "MiddleOne 생성자" << endl;
    }
    void MiddleOneFunc()
    {
        cout << "MiddleOne" << endl;
    }
};
class MiddleTwo : virtual public Base
{
public:
    MiddleTwo() : Base()
    {
        cout << "MiddleTwo 생성자" << endl;
    }
    void MiddleTwoFunc()
    {
        cout << "MiddleTwo" << endl;
    }
};
class Last : public MiddleOne, public MiddleTwo
{
public:
    Last() : MiddleOne(), MiddleTwo()
    {
        cout << "Last 생성자" << endl;
    }
    void ComplexFunc()
    {
        MiddleOneFunc();
        MiddleTwoFunc();
        // SimpleFunc 같은 경우 MiddleOne과 MiddleTwo 둘다 상속 받기 떄문에 어느걸을 참조할지 모르기 떄문에 오류발생
        // 그러므로 Base를 상속받는 클래스에 Base를 상속받을 때 접근지정자 앞에 virtual 키워드를 붙여 가상화를 해준다.
        // 만약 virtual을 안하고 simpleFunc를 사용하지 않는다면 작동은 되지만 Base생성자를 2번 호출하게 된다.
        SimpleFunc(); 
    }
};
int main()
{
    Data obj1 = { 20, ShowData, Add };
    Data obj2 = { 7, ShowData, Add };
    obj1.Add(&obj1,30);
    obj2.Add(&obj2, 70);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);

    cout << "객체 생성 전" << endl;
    Last ldr;
    cout << "객체 생성 후" << endl;
    ldr.ComplexFunc();

    std::cout << "\nEnd Of Main\n";
}