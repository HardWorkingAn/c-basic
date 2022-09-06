#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    
    void* operator new(size_t size)
    {
        cout << "operator new() : " << size << endl;
        void* adr = new char[size];
        return adr;
    }
    void* operator new[](size_t size)
    {
        cout << "operator new[] (배열) : " << size << endl;
        void* adr = new char[size];
        return adr;
    }
    void operator delete(void* adr)
    {
        cout << "operator delete()" << endl;
        delete[] adr;
    }
    void operator delete[](void* adr)
    {
        cout << "operator delete[] (배열)" << endl;
        delete[] adr;
    }
    friend ostream& operator<<(ostream& os, const Point& pos);
    // operator() 을 하기위한 작성
    Point operator+(const Point& pos1) const
    {
        return Point(xpos + pos1.xpos, ypos + pos1.ypos);
    }
};
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}
//포인터 오버로딩
class Number
{
private:
    int num;
public:
    Number(int n1) : num(n1) {}
    void ShowData()
    {
        cout << num << endl;
    }
    Number* operator->()
    {
        return this;
    }
    Number& operator*()
    {
        return *this;
    }
};
//스마트 포인터
class Point2
{
private:
    int xpos, ypos;
public:
    Point2(int x = 0, int y = 0) : xpos(x), ypos(y) { cout << "Point 객체 생성" << endl; }
    ~Point2()
    {
        cout << "Point 객체 소멸" << endl;
    }
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    friend ostream& operator<<(ostream& os, const Point2& pos);
};
class SmartPtr
{
private:
    Point2* posptr;
public:
    SmartPtr(Point2* ptr) : posptr(ptr) {}
    Point2& operator*() const
    {
        return *posptr;
    }
    Point2* operator->() const
    {
        return posptr;
    }
    ~SmartPtr()
    {
        delete posptr;
    }
};

ostream& operator<<(ostream& os, const Point2& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

//operator() 펑터(Functor) : 함수처럼 작동되는 클래스
class Adder
{
public:
    int operator()(const int& n1, const int& n2)
    {
        return n1 + n2;
    }
    double operator()(const double& n1, const double& n2)
    {
        return n1 + n2;
    }
    Point operator()(const Point& n1, const Point& n2)
    {
        return n1 + n2;
    }
};
// 펑터를 이용한 버블정렬
class SortRule
{
public:
    virtual bool operator()(int num1, int num2) const = 0; //가상함수화
};

class AscendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 > num2)
            return true;
        else
            return false;
    }
};
class DescendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};
class DataStorage
{
private:
    int* arr;
    int idx;
    const int MAX_LEN;
public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
    {
        arr = new int[MAX_LEN];
    }
    void AddData(int num)
    {
        if (MAX_LEN <= idx) {
            cout << "더 이상 저장할 수 없습니다." << endl;
            return;
        }
        arr[idx++] = num;
    }
    void ShowAllData()
    {
        for (int i = 0; i < idx; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    void SortData(const SortRule& functor)
    {
        for (int i = 0; i < ( idx - 1 ); i++) {
            for (int j = 0; j < ( idx - 1); j++) {
                if (functor(arr[j], arr[j + 1])) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};
//임시객체 자동형변환
class Number2
{
private:
    int num;
public:
    Number2(int n = 0) : num(n) { cout << "Number2(int n = 0)" << endl; }
    void ShowNumber() { cout << num << endl; }
    Number2& operator=(const Number2& ref)
    {
        cout << "operator=()" << endl;
        num = ref.num;
        return *this;
    }
    operator int() // 형 변환 연산자의 오버로딩
    {
        cout << "형 변환 " << num << endl;
        return num;
    }
};

int main()
{
    // operator new 와 delete는 static 함수 이므로 Point 객체가 완성 전이라도 호출이 가능하다.
    Point* ptr = new Point(3, 4); //Point 할당 중이므로 아직 Point는 생성되지 않은 상태
    cout << *ptr;
    Point* arr = new Point[3];
    arr[0] = Point(5, 7);
    cout << arr[0];

    delete ptr;
    delete[] arr;
    // 포인터 오버로딩
    Number num(20);
    

    (*num) = 30;
    num->ShowData(); //num은 포인터가 아니지만 오버로딩을 통해 작동
    (*num).ShowData();
    
    // 스마트포인터
    SmartPtr sptr1(new Point2(1, 2));
    SmartPtr sptr2(new Point2(3, 4));
    SmartPtr sptr3(new Point2(5, 6));

    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;
    
    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);

    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    // operator()
    Adder adder;
    cout << adder(1, 3) << endl;
    cout << adder(1.5, 3.2) << endl;
    cout << adder(Point(3,4), Point(6,8)) << endl;
    // 펑터를 이용한 버블정렬
    DataStorage store(5);
    store.AddData(40);
    store.AddData(16);
    store.AddData(73);
    store.AddData(25);
    store.AddData(82);

    store.ShowAllData();

    store.SortData(AscendingSort());
    store.ShowAllData();

    store.SortData(DescendingSort());
    store.ShowAllData();
    cout << endl;
    //임시객체 자동형변환
    //Number2 num1(100);
    //Number2 num2(0);
    //num2 = num1;
    //num2.ShowNumber();
    Number2 number(0);
    number = 30; // 30 이란 숫자는 number의 대입연산자에서 형식이 맞지 않으므로 Number2(30) 으로 임시객체로 변환후 number.operator=(Number(30)) 으로 됨
    number.ShowNumber();

    Number2 number2 = number + 20; // operator int 를 통해 number 을 숫자로 30으로 변환하고 30 + 20 해서 50으로 연산후 임시객체로 만들어 operator= 작동
    number2.ShowNumber();

    std::cout << "\nEnd Of Main\n";
}