#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
    }
    void ShowPoint() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
   
    //맴버 함수를 이용한 오버로딩 
    Point operator+(const Point& ref)
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
    // 문제 10-1 409p
    //문제1
    friend Point operator-(const Point& ref1, const Point& ref2);
    //문제2
    Point operator+=(const Point& ref)
    {
        xpos += ref.xpos;
        ypos += ref.ypos;
        return *this;
    }
    
    Point operator-=(const Point& ref)
    {
        xpos -= ref.xpos;
        ypos -= ref.ypos;
        return *this;
    }
    //문제3
    friend bool operator==(const Point& ref1, const Point& ref2);
    friend bool operator!=(const Point& ref1, const Point& ref2);
    // 전역함수를 이용한 오버로딩 
    friend Point operator+(const Point& ref1, const Point& ref2); 
    
    Point AddPoint(const Point& ref)
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }

    Point& operator++() 
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point& operator--(Point& ref);
    //문제 10-2
    Point operator- ()
    {
        Point pos(-xpos, -ypos);
        return pos;
        //xpos *= -1;
        //ypos *= -1;
        //return *this;
        
    }
    friend Point operator~(const Point& ref);
    //후위증감
    Point operator++(int)
    {
        const Point retobj(xpos, ypos); // const Point(retobj(*this)
        xpos += 1;
        ypos += 1;
        return retobj;
    }
    friend const Point operator--(Point& ref, int); // 후위감소

    //교환법칙
    Point operator*(int times) 
    {
        Point pos(xpos * times, ypos * times); //맴버함수의 xpos와 ypos를 곱한거를 임시객체 pos를 만들고 임시객체 리턴
        return pos;
    }
    friend Point operator*(int times, const Point& ref);
    //입출력 연산자 오버로딩 문제10-3
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point& pos);

};

Point operator+(const Point& ref1, const Point& ref2)
{
    Point pos(ref1.xpos + ref2.xpos, ref1.ypos + ref2.ypos);
    return pos;
}
Point operator-(const Point& ref1, const Point& ref2)
{
    Point pos(ref1.xpos - ref2.xpos, ref1.ypos - ref2.ypos);
    return pos;
}
bool operator==(const Point& ref1, const Point& ref2) {
    if (ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos)
        return true;
    else
        return false;
}
bool operator!=(const Point& ref1, const Point& ref2) {
    //ref1==ref2 연산자 오버로딩이 이미 되어있기 때문에 아용
    return !(ref1 == ref2);
}

Point& operator--(Point& ref) 
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}
//문제 10-2
Point operator~(const Point& ref)
{
    Point pos(ref.ypos, ref.xpos);

    return pos;
}
//후위감소
const Point operator--(Point& ref, int) //상수값 반환타입
{
    const Point retobj(ref); //상수값 전달
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj; //변환값이 const(상수)이기 때문에 새로운 Point에 값을 넣을 수 있다.
}
Point operator*(int times, Point& ref) // 3 * ref 일 경우 오류가 발생하기 떄문에 방지
{
    return ref * times; // 맴버변수의 operator*(int times) 호출
}
//입출력 연산자 오버로딩 문제10-3
//ostream과 isteam은 iosteam 파일 안에있다.
ostream& operator<<(ostream& os, const Point& pos) // 숫자를 출력해야하기 때문에 Point를 상수화
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

istream& operator>>(istream& is, Point& pos)
{
    is >> pos.xpos >> pos.ypos;
    return is;
}
int main()
{

    Point pos1(3, 4);
    Point pos2(10, 20);

    //Point pos3 = pos2.operator+(pos1);

    // + 연산은 원래 안되지만 연산자 오버로딩을 통해서 묵시적으로 pos1.operator+(pos2)가 작동된다.
    // 맴버함수 오버로딩이 없으면 전역함수를 이용하게 되어 operator+(pos1, pos2)가 된다.
    Point pos4 = pos1 + pos2; 
    Point pos5 = pos1.AddPoint(pos2);
    
    pos1.ShowPoint();
    pos2.ShowPoint();
    //pos3.ShowPoint();
    pos4.ShowPoint();
    pos5.ShowPoint();

    //문제 10-1
    Point pos_answer1 = pos1 - pos2;
    cout << "pos1 - pos2 : "; pos_answer1.ShowPoint();
    Point pos_answer2 = operator-(pos1, pos4);
    cout << "operator-(pos1, po4) : "; pos_answer2.ShowPoint();
    Point pos6(5, 10);
    cout << "pos6 : "; pos6.ShowPoint();
    Point pos7(7, 11);
    cout << "pos7 : "; pos7.ShowPoint();
    //문제 10-1
    pos6.operator+=(pos7);
    cout << "pos6 += pos7 "; pos6.ShowPoint();
    pos6.operator-=(pos7);
    cout << "pos6 -= pos7 "; pos6.ShowPoint();
    if (pos6 == pos7)
        cout << "pos6==pos7 : true " << endl;
    else
        cout << "pos6==pos7 : false " << endl;
    if(pos6 != pos7)
        cout << "pos6!=pos7 : true " << endl;
    else
        cout << "pos6!=pos7 : false " << endl;
    std::cout << "\nEnd of Main\n";

    Point pos8(2, 3);
    cout << "pos8 : "; pos8.ShowPoint();
    ++pos8;
    cout << "++pos8  "; pos8.ShowPoint();
    pos8.operator++();
    cout << "pos8.operator++() "; pos8.ShowPoint();
    --pos8;
    cout << "--pos8  "; pos8.ShowPoint();
    operator--(pos8);
    cout << "operator--(pos8) "; pos8.ShowPoint();
    ++(++pos8);
    cout << "++(++pos8)  "; pos8.ShowPoint();
    operator--(operator--(pos8));
    cout << "operator--(operator--(pos8)) "; pos8.ShowPoint();
    //문제 10-2 단항연산자
    Point pos9 = -pos8;
    pos9.ShowPoint();
    cout << "~pos9 : ";
    operator~(pos9);
    (~pos9).ShowPoint(); //~pos9 리턴값은 참조값 수정이 아닌 임시객체 를 리턴하기 때문에 pos9의 변화란 무관하다.
    pos9.ShowPoint();

    pos9++;
    cout << "pos9++ "; pos9.ShowPoint();
    operator--(pos9);
    cout << "operator--(pos9) "; pos9.ShowPoint();
    //const로 하지 않았기 때문에 가능 하지만 한번 값 변경후 리턴값이 임시 객체이기 때문에 외부++는 변하지 않는다.
    //또한 후위증가에서는 임시객체에 대한 증가값은 따로 없기 떄문에 pos10은 원래의 pos9의 값을 가진다.
    Point pos10 = (pos9++)++; 
    //(pos9--)--; error 타입이 pos9--값은 주소값이 아닌 상수값이기 때문에 불가능하다.
    cout << "pos9 : "; pos9.ShowPoint();
    cout << "pos10 : "; pos10.ShowPoint();
    Point pos11 = pos9--; //이것 또한 임시객체로 받기 때문에 pos11은 기존의 pos9의 값을 가진다.
    cout << "pos11 : "; pos11.ShowPoint();

    Point pos12(1, 2);
    Point pos13 = pos12 * 3;  //맴버함수의 xpos와 ypos를 곱한거를 임시객체 pos를 만들고 임시객체 리턴 pos12값은 변환x
    cout << "pos13 : "; pos13.ShowPoint();
    Point pos14 = 5 * pos12; // 전역함수로 오버로딩으로 pos12 * 5 로 변환시켜 pos12.operator(5)로 변환되어 리턴받음
    cout << "pos14 : "; pos14.ShowPoint(); 
    
    //입출력 연산자 오버로딩 문제10-3
    Point pos15;
    cout << "x,y 좌ㅣ표 순으로 입력 : ";
    cin >> pos15; // operator>>(istream& is, const Point& pos)
    cout << "pos15 : "; cout << pos15; // ShowPoint() 함수를 사용x
}