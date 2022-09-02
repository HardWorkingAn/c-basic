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


    std::cout << "\nEnd Of Main\n";
}