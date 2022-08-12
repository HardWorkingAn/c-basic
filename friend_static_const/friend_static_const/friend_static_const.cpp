#include <iostream>
#include <cstring>
using namespace std;

//const 와 cosnt 오버로딩
/*
class SoSImple {
private:
    int num;
public:
    SoSImple(int n):num(n) {

    }
    SoSImple& AddNum(int n) {
        num += n;
        return *this;
    }
    void ShowData() const{
        cout << "num : " << num << endl;
    }
    void ShowConst() {
        cout << "Not Const" << endl;
    }
    void ShowConst() const {
        cout << "Yes Const" << endl;
    }
};
*/
//friend
//friend를 쓰게 된다면 private로 설정한것도 참조가 가능해져서 캡슐화에 위반되기 떄문에 사용을 자재
/*
class Girl; // Boy에서 Girl을 참조할때 위에 선언된게 없으면 사용을 못하기 떄문에 미리 선언

class Boy {
private:
    int height;
    friend class Girl;
public:
    Boy(int len) :height(len){}
    void ShowYourFriendInfo(Girl& frn);
};
class Girl {
private:
    char phoneNum[20];
public:
    Girl(const char* num) {
        strcpy(phoneNum, num);
    }
    void ShowYourFriendInfo(Boy& frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn) {
    cout << "Her phone number : " << frn.phoneNum << endl;
};

void Girl::ShowYourFriendInfo(Boy& frn) {
    cout << "His Height : " << frn.height << endl;
};
*/
/*
class Point;

class PointOP {
private:
    int opcnt;
public:
    PointOP():opcnt(0)
    {}
    Point PointAdd(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
    ~PointOP() {
        cout << "Operation times : " << opcnt << endl;
    }
};

class Point {
private:
    int x, y;
public:
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos)
    {}
    friend Point PointOP::PointAdd(const Point&, const Point&); // PointOP::PointAdd에 대해서 Point 의 private을 참조해도 된다는 의미
    friend Point PointOP::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&);
};
Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
    opcnt++;
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
    opcnt++;
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}
void ShowPointPos(const Point& pnt) {
    cout << "x : " << pnt.x << ", y : " << pnt.y << endl;
}
*/
//static
//전역변수 static은 선언된 파일 내에서만 참조를 허용하겠다는 의미
//지역변수 static은 한번만 초기화되고 함수를 빠져나가도 소멸x
/*
//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple {
private:
    int simObjCnt;
    static int static_simObjCnt;
public:
    SoSimple() :simObjCnt(0)
    {
        simObjCnt++;
        static_simObjCnt++;
        cout << simObjCnt << "번째 SoSimple 객체" << endl;
        cout << static_simObjCnt << "번째 static_SoSimple 객체" << endl;
    }
    static void Adder(int n) 
    {
        // 함수가 static 이므로 프로그램 시작할때 제일먼저 할당되는데 Adder를 사용할 때 지역변수는 생성이 되지않아 오류발생
        //simObjCnt += n; 
        static_simObjCnt += n;
    }
};
int SoSimple::static_simObjCnt = 0;

class SoComplex 
{
private:
    static int static_cmxObjCnt;
public:
    SoComplex() 
    {
        //cmxObjCnt++;
        //cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
        static_cmxObjCnt++;
        cout << static_cmxObjCnt << "번째 Static_SoComplex 객체" << endl;
    }
    SoComplex(SoComplex& copy) 
    {
        //cmxObjCnt++;
        //cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
        static_cmxObjCnt++;
        cout << static_cmxObjCnt << "번째 Static_SoComplex 객체" << endl;
    }
};
int SoComplex::static_cmxObjCnt = 0;
*/
//const static , mutable
class ConutryArea {
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CANIA = 957290;
    const static int SOUTH_KOREA = 9922;
};
class SoSimple {
private:
    int num1;
    mutable int num2; // const로 지정된 함수에 대해서는 예외로 변경가능
public:
    SoSimple(int n1, int n2)
        :num1(n1), num2(n2)
    {
    }
    void ShowSimpleData() const 
    {
        cout << num1 << ", " << num2 << endl;
    }
    //const 설정하면 맴버변수는 이 함수안에서 값을 변경 할수 없다는 의미
    void CopyToNum2() const 
    {
        cout << "mutable num2 변수에 num1 값 저장" << endl;
        num2 = num1; // 하지만 num2 는 mutable 설정했으므로 가능
        int num3 = 10; //맴버 변수가 아닌 지역변수 이기 때문에 가능
        cout << "const 함수 내 지역 변수 생성 : " << num3 << endl;
    }
};
int main()
{
    //const 와 cosnt 오버로딩
    /*
    SoSImple obj1(7);
    const SoSImple obj2(9);
    obj1.AddNum(20);
    // obj2.AddNum(10); // 변수가 const이기 떄문에 안의 값은 변경이 불가능하다.
    obj1.ShowData();
    obj2.ShowData();

    obj1.ShowConst();
    obj2.ShowConst();
    */
    //friend
    /*
    Boy boy(170);
    Girl girl("010-1111-2222");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    */
    /*
    Point pos1(1, 2);
    Point pos2(3, 4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos1, pos2));
    */
    //static
    /*
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();
    */
    //const static , mutable
    
    cout << "러시아 면적 : " << ConutryArea::RUSSIA << endl;
    cout << "캐나다 면적 : " << ConutryArea::CANADA << endl;
    cout << "중국 면적 : " << ConutryArea::CANIA << endl;
    cout << "한국 면적 : " << ConutryArea::SOUTH_KOREA << endl;

    SoSimple sm(1, 2);
    sm.ShowSimpleData();
    sm.CopyToNum2();
    sm.ShowSimpleData();

    std::cout << "\nEnd Of Main\n";
}