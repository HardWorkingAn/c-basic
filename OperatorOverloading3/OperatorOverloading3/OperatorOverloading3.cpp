#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) :xpos(x), ypos(y) {};
    friend ostream& operator<<(ostream& os, const Point& pos);

    //문제 11-2 1번 468p
    friend ostream& operator<<(ostream& os, const Point* pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}
//문제 11-2 1번 468p
ostream& operator<<(ostream& os, const Point* pos) {
     os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
     return os;
}


typedef Point* POINT_PTR;// 연산의 주 대상이 포인터인 경우 이렇게 자료형을 정의하는 것이 좋다.
// 대입연산자 [] 오버로딩
class BoundCkeckIntArray
{
private:
    //Point* arr;
    POINT_PTR* arr;
    int arrlen;
    // 배열은 저장소의 일종이고 저장소의 데이터는 유일성이 보장해야 하기 떄문에 이런식 배열의 복사를 막아서 코드와 데이터의 안정성을 높일 수 있다.
    BoundCkeckIntArray(const BoundCkeckIntArray& arr) {};
    BoundCkeckIntArray operator=(const BoundCkeckIntArray& arr) {};
public:
    BoundCkeckIntArray(int len) : arrlen(len)
    {
        arr = new POINT_PTR[len];
    }
    POINT_PTR& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "배열 밖으로 벗어남" << endl;
            exit(1);
        }
        return arr[idx];
    }
    POINT_PTR operator[](int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "배열 밖으로 벗어남" << endl;
            exit(1);
        }
        return arr[idx];
    }
    ~BoundCkeckIntArray()
    {
        delete[] arr;
    }
    int GetArrLen() const { return arrlen; }  
};

void ShowAllData(BoundCkeckIntArray& ref)
{
    int len = ref.GetArrLen();
    for (int idx = 0; idx < len; idx++)
        cout << ref[idx] << endl;
};
//문제 11-2 2번 468p
class Bound2DIntArray
{
private:
    int* arr;
    int arrlen;
    Bound2DIntArray(const Bound2DIntArray& arr) {};
    Bound2DIntArray operator=(const Bound2DIntArray& arr) {};
public:
    Bound2DIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "배열 밖으로 벗어남" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[](int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "배열 밖으로 벗어남" << endl;
            exit(1);
        }
        return arr[idx];
    }
    ~Bound2DIntArray()
    {
        delete[] arr;
    }
    int GetArrLen() const { return arrlen; }
};
typedef Bound2DIntArray* Bound2DIntArrayPtr;

class BoundCheck2DIntArray
{
private:
    Bound2DIntArrayPtr* arr;
    int arrlen;
    BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray&) {};
    BoundCheck2DIntArray(const BoundCheck2DIntArray&) {};
public:
    BoundCheck2DIntArray(int col, int row) : arrlen(col)
    {
        //배열 안에 배열을 생성
        arr = new Bound2DIntArrayPtr[col];  // 3개의 공간생성
        for (int i = 0; i < col; i++)
        {
            arr[i] = new Bound2DIntArray(row); // 공간마다 4개의 공간을 또 생성
        }
    }
    Bound2DIntArray& operator[](int idx){
        
        if (idx < 0 || idx >= arrlen) {
            cout << "배열 밖 벗어남" << endl;
            exit(1);
        }

        return *(arr[idx]); //자기 자신의 주소값을 전달하여 연속으로 연산자 호출
    }
    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i < arrlen; i++)
            delete arr[i];
        delete[] arr;
    }
};

int main()
{
    /*
    BoundCkeckIntArray arr(4);
    arr[0] = Point(3, 4);
    arr[1] = Point(5, 6);
    arr[2] = Point(7, 8);
    arr[3] = { 6,2 };
    */
    BoundCkeckIntArray arr(3);
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);
    int len = arr.GetArrLen(); // 직접 for문안에 arr.GetArrLen() 써도되지만 반복횟수가 많을수록 이 방법이 속도면에서 좋다.
    for (int i = 0; i < len; i++)
    {
        //cout << *(arr[i]);

        //문제 11-2 1번 468p
        cout << arr[i];
    }
    delete arr[0];
    delete arr[1];
    delete arr[2];

    BoundCheck2DIntArray arr2d(3, 4);
    for (int n = 0; n < 3; n++)
        for (int m = 0; m < 4; m++)
            arr2d[n][m] = n + m;

    for (int n = 0; n < 3; n++) {
        for (int m = 0; m < 4; m++)
            cout << arr2d[n][m] << ' ';
        cout << endl;
    }



    std::cout << "\nEnd Of Main\n";
}
