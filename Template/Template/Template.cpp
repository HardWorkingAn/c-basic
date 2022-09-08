#include <iostream>
using namespace std;
// 아무 타입이나 쓸수 있도록 탬플릿 함수
template <typename T>
T Add(T num1, T num2)
{
    cout << "T Add(T num1, T num2)" << endl;
    return num1 + num2;
}
int Add(int num1, int num2)
{
    cout << "int Add(int num1, int num2)" << endl;
    return num1 + num2;
}
double Add(double num1, double num2)
{
    cout << "double Add(double num1, double num2)" << endl;
    return num1 + num2;
}
template<class T1, class T2>
void ShowData(double num)
{
    cout << (T1)num << ", " << (T2)num << endl;
}

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << "]" << endl;
    }
};
//문재 13-1 1번 535p
template<class T>
void SwapData(T& class1, T& class2)
{
    T temp = class1;
    class1 = class2;
    class2 = temp;
}
//문재 13-1 2번 536p
template<typename T>
T SumArray(T arr[], int len)
{
    T sum = (T)0; //T타입으로 캐스팅(사실상 형식적)
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
template<typename T>
T Max(T a, T b)
{
    cout << "T Max(T a, T b)" << endl;
    return a > b ? a : b;
}
//밑에 같은 경우 템플릿을 사용할 때 아래에 해당되는 타입이 나오면 아래 함수를 사용 오버라이딩
template<>
char* Max(char* a, char* b)
{
    cout << "char* Max<char*> (char* a, char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
}
const char* Max(const char* a, const char* b)
{
    cout << "const char* Max<char*> (const char* a, const char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
}
//클래스 탬플릿
template<typename T>
class T_Point
{
private:
    T xpos, ypos;
public:
    //파일 분리 정의 하기위해 주석처리
    //T_Point(T x = 0, T y = 0) : xpos(x), ypos(y)
    //{    }
    //void ShowPosition()
    //{
    //    cout << '[' << xpos << " ," << ypos << ']' << endl;
    //}
    T_Point(T x = 0, T y = 0);
    void ShowPosition() const;
};
//함수 분리
template<typename T>
T_Point<T>::T_Point(T x, T y) : xpos(x), ypos(y){}

template<typename T>
void T_Point<T>::ShowPosition() const
{
    cout << '[' << xpos << " ," << ypos << ']' << endl;
}
//파일 분리
// 파일 분리하여 템플릿을 저장할 때 h파일 안에 정의와 선언 다 해줘서 h파일만 include 하던가 
// 선언한 cpp 파일도 include 해줘야지 에러가 발생하지 않는다. 보통 템플릿은 h파일 안에 정의와 선언다 해준다.
// 자세한내용 책 546p
#include "PointTemplate.h"
#include "PointTemplate.cpp" 
//파일분리 컴파일 테스트
#include "test1.h"
//배열 클래스템플릿 test.h 재사용함
#include "BoundCheckArray.h"
//문제 13-2 552p
#include "SmartPointer.h"

int main()
{
    
    cout << Add(15, 20) << endl;
    cout << Add(2.9, 3.7) << endl;
    cout << Add<int>(3.2, 3.2) << endl;
    cout << Add<double>(3.14, 2.27) << endl;

    ShowData<char, int>(65);
    ShowData<char, int>(67);
    ShowData<char, double>(68.9);
    ShowData<short, double>(69.2);
    ShowData<short, double>(70.4);
    //문재 13-1 1번 535p
    Point pos1(3, 4);
    pos1.ShowPosition();
    Point pos2(7, 8);
    pos2.ShowPosition();
    SwapData<Point>(pos1, pos2);
    cout << "----------SwpaData()-----------" << endl;
    pos1.ShowPosition();
    pos2.ShowPosition();
    cout << endl;
    //문재 13-1 2번 536p
    int arr1[] = { 10,20,60,40 };
    cout << SumArray<int>(arr1, sizeof(arr1) / sizeof(int)) << endl;
    double arr2[] = { 20.2, 60.25, 26.32, 10.1 };
    cout << SumArray<double>(arr2, sizeof(arr2) / sizeof(double)) << endl;
    cout << endl;
    
    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;
    cout << Max(3.5, 7.5) << endl;
    cout << Max("Best", "Simple") << endl; 

    char str1[] = "Simple";
    char str2[] = "Best";
    cout << Max(str1, str2) << endl;
    cout<<endl;
    // 클래스 탬플릿은 해더파일 안에 선언과 정의 한번해 해줘야함 아니면 cpp 파일까지 include 해줘야함. 보통 전자를 사용
    T_Point<int> T_pos1(3, 4);
    T_pos1.ShowPosition();
    T_Point<double> T_pos2(2.4, 3.6);
    T_pos2.ShowPosition();
    T_Point<char> T_pos3('P', 'F');
    T_pos3.ShowPosition();

    PointTemplate<int> PT_pos1(10, 11);
    PT_pos1.ShowPosition();
    PointTemplate<double> PT_pos2(5.2, 7.51);
    PT_pos2.ShowPosition();
    PointTemplate<char> PT_pos3('A', 'B');
    PT_pos3.ShowPosition();
    cout << endl;

    // 기존 클래스 파일분리 테스트
    test1 test_t1(10, 5);
    test_t1.show();
    test1 test_t2(2, 4);
    test_t2.show();

    //배열 클래스템플릿
    BoundCheckArray<int> iarr(5);
    for (int i = 0; i < iarr.GetArrLen(); i++)
        iarr[i] = (i + 1) * 11;
    for (int i = 0; i < iarr.GetArrLen(); i++)
        cout << iarr[i] << endl;
    cout << endl;

    BoundCheckArray<test1> pointArr(3);
    pointArr[0] = test1(4, 7);
    pointArr[1] = test1(59, 35);
    pointArr[2] = test1(453, 854);
    for (int i = 0; i < pointArr.GetArrLen(); i++)
        cout << pointArr[i];
    cout << endl;

    typedef test1* POINT_PTR; //포인터를 이용하여 동적 생성
    BoundCheckArray<POINT_PTR> pointPtrArr(3);
    pointPtrArr[0] = new test1(2, 3);
    pointPtrArr[1] = new test1(33, 44);
    pointPtrArr[2] = new test1(555, 666);
    for (int i = 0; i < pointPtrArr.GetArrLen(); i++)
        cout << *(pointPtrArr[i]);
    delete pointPtrArr[0];
    delete pointPtrArr[1];
    delete pointPtrArr[2];
    cout << endl;

    //문제 13-2 552p
    SmartPtr<test1> sptr1(new test1(1, 2));
    SmartPtr<test1> sptr2(new test1(3, 4));
    sptr1->show();
    sptr2->show();

    sptr1->SetPos(55, 66);
    sptr2->SetPos(111, 222);
    sptr1->show();
    sptr2->show();

    std::cout << "\nEnd Of Main\n";
}