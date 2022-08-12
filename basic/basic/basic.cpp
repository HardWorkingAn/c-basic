#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

// 오버로딩 합수
/*
int MyFunc(int num){
    num *= num;
    return num;
}
int MyFunc(int a, int b) {
    a = a * b;
    return a;
}
*/
//swap 함수
/*
void swap(int* num1, int* num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/
//인라인 함수 define 매크로설정
//inline 함수
//인라인 함수를 사용하면 int main안에서 컴파일 한것으로 판단한다.
//하지만 인라인 함수가 성능에 해가 될경우 컴파일에서 자동으로 키워드를 무시한다. 또한 컴파일이 필요할 경우 일부 함수를 인라인화한다.
//함수가 자주 호출되는 경우 인라인 화 하면 외부에서 호출 할 필요가 없기 떄문에 좀더 빠르게 실행된다.
inline int SQUARE_inline(int x) {
    return x * x;
}
//매크로 함수를 사용하면 일반적인 함수에 비해서 속도의 이점이 있다.
#define SQUARE(x) ((x)*(x))

//네임스페이스
/*
namespace test {
    void func(){
        cout << "namespace 안의 func함수 출력\n";
    }
    void main(){
        cout << "namespace 을 이용한 예약어를 변수로 사용\n";
    }
    void string(); //이름만 선언하고 다른곳에서 정의 가능
}
void test::string(){
    cout << "test::string\n";
}//namespace를 따로 분리해도 이름이 같으면 같은공간
namespace BestComImp {
    void SimpleFunc();
}
namespace BestComImp {
    void PrettyFunc();
}
namespace ProgComImp {
    void SimpleFunc();
}
void BestComImp::SimpleFunc() {
    cout << "BestCom::simple\n";
    PrettyFunc(); //namespace를 분리했지만 BestCom 네임스페이스 안에 simple과 Pretty 같이 있음
    // SimpleFunc(); 할경우 자기 자신을 부르는 회귀함수가 된다.
    ProgComImp::SimpleFunc(); //다른 이름공간에 있는 SimpleFunc를 부른다.
    
}
void BestComImp::PrettyFunc() {
    cout << "BestCom :: pretty\n";
}
void ProgComImp::SimpleFunc() {
    cout << "ProgCom :: simple\n";
}

namespace AAA {
    namespace BBB {
        namespace CCC {
            int num1;
            int num2;
        }
    }
}
*/
// ::(범위지정연산자) 이용한 지역변수와 전역변수명 같을 때 전역변수 따로 값증가
/*
int val = 10;
int simplefunc(){
    int val = 20; //지역변수
    ::val += 55; // 전역변수
    return val; //지역변수 리턴
}
*/
//참조자, 포인터
/*
int* SimpleFunc(int* ptr) {
    if (ptr == NULL) {
        return NULL;
    }
    *ptr = 20;
    return ptr;
}
*/
//참조자 포인터 문제
/*
//문제02 - 1 문제1 80p
void incrementInt(int &num) {
    num += 1;
}
void reverseInt(int& num) {
    num *= -1;
}
//문제02 - 1 문제3 80p
void SwapPointer(int *(&ptr1), int *(&ptr2)) {
    int* temp;
    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
    
}
*/
//참조자 const
/*
int& RefRetFuncOne(int& ref) { 
    ref++;
    return ref;
}
int& RefRetFuncTwo(int ref) { //참조타입으로 반환할 경우 매개변수가 참조형이 아닐때 ref는 주소를 반환한다.
    ref++;
    return ref;
}

int Adder(const int& num1, const int& num2) {
    return num1 + num2;
}
*/

//new delete 키워드
/*
char* MakeStrAdr_malloc(int len) {
    char* str = (char*)malloc(sizeof(char) * len);
    return str;
}
char* MakeStrAdr_new(int len) {
    char* str = new char[len];
    return str;
}

class Simple{
public:
    Simple() {
        cout << "Simple~\n";
    }
};
*/
//구조체에 대한 new delete 문제 02-3 95p
typedef struct __Point
{
    int xpos;
    int ypos;
} Point;
Point& PntAdder(const Point& p1, const Point& p2) {
    Point sum;
    sum.xpos = p1.xpos + p2.xpos;
    sum.ypos = p1.ypos + p2.ypos;
    return sum;
}
int main()
{
    /* 
    char a[100];
    string b;

    scanf("%s", a);
    cout << a << endl;

    cin >> b;
    cout << b << endl;
    
    int x, y, sum;
    cin >> x >> y;

    sum = x + y;

    cout << "x + y = " << sum << endl;
    */
    // 오버로딩
    /*
    int a;
    int b;
    a = MyFunc(10);
    b = MyFunc(10, 11);

    cout << a << "\n" << b;
    */
    //swap 예제
    /*
    int num1 = 10, num2 = 20;
    swap(&num1, &num2);
    cout << num1 << "  " << num2 << endl;

    int a = 30, b = 40;
    swap(a, b);
    cout << a << "  " << b;
    */
    //매크로 이용 및 인라인 사용
    /*
    cout << SQUARE(5) << endl;
    
    cout << SQUARE_inline(10) << endl;
    */
    //네임스페이스
    /*
    test::func();
    test::main();
    test::string();
    BestComImp::SimpleFunc();
    using test::func; //using test::func를 하면 func함수를 호출할 떄 test::를 생략 가능
    func();
    // namespace 키워드를 통째로 using 하면 BestComImp안에있는 함수를 통째로 BestComImp::를 안해도된다.
    // 하지만 예약어를 네임스페이스를 사용하여 변수로 사용하고 있다면 그 변수는 따로 네임스페이스를 써줘야 한다.
    using namespace BestComImp; 
    SimpleFunc();
    
    namespace ABC = AAA::BBB::CCC; // 네임스페이스 변수를 사용하여 단축가능
    AAA::BBB::CCC::num1 = 10;
    ABC::num2 = 20;

    cout << AAA::BBB::CCC::num1 << endl;
    cout << ABC::num2 << endl;
    */
    // ::(범위지정연산자) 이용한 지역변수와 전역변수명 같을 때 전역변수 따로 값증가
    /*
    cout << simplefunc() << endl; //지역변수 val 20 출력
    cout << val << endl; //전역변수 val 10 + 55(simplefunc호출로 인한 값 증가) 65 출력
    */

    //참조자, 포인터
    /*
    int num = 12;
    int* ptr = &num; //num 포인터값을 ptr에 저장
    int** dptr = &ptr; // num의 포인터값을 가진 ptr의 포인터값을 dptr에 저장

    cout << num << endl; 
    cout << *ptr << endl; 
    cout << **dptr << endl;

    **dptr = 123;

    int& ref = num; // num을 참조
    int *(&pref) = ptr; // 포인터를 참조
    int **(&dpref) = dptr; // 이중포인터를 참조

    cout << num << endl;
    cout << *pref << endl;
    cout << **dpref << endl;

    int& test1 = ref; 
    int* test2 = &ref;

    **dpref = 20;

    cout << test1 << endl;
    cout << *test2 << endl;
    //---
    int num1 = 12;

    int* ptr = SimpleFunc(&num1); //함수의 타입이 int 포인터 타입이기 때문에 포인터로 받아야한다.
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << num1 << endl;
    */
    //참조자 포인터 문제
    /*
    //문제02 - 1 문제1 80p
    int answer = 1;
    incrementInt(answer);
    cout << answer << endl;
    reverseInt(answer);
    cout << answer << endl;

    //문제02 - 1 문제3 80p
    int answer_num1 = 10;
    int answer_num2 = 20;

    int* ptr1 = &answer_num1;
    int* ptr2 = &answer_num2;

    cout << "*ptr1 : " << *ptr1 << endl;
    cout << "ptr1 : " << ptr1 << endl;
    cout << "*ptr2 : " << *ptr2 << endl;
    cout << "ptr2 : " << ptr2 << endl;

    SwapPointer(ptr1, ptr2);

    cout << "*ptr1 : " << *ptr1 << endl;
    cout << "ptr1 : " << ptr1 << endl;
    cout << "*ptr2 : " << *ptr2 << endl;
    cout << "ptr2 : " << ptr2 << endl;
    */
    //참조자 const
    /*
    int b = 20;
    int b2 = RefRetFuncOne(b);

    cout << b << endl;
    cout << b2 << endl; // b2는 RefRetFuncOne 값(value)만 리턴받기 떄문에 b의 참조값과 별개. 다른주소값

    int& b_ref = RefRetFuncTwo(b);

    b2 += 100;
    cout << b << endl;
    cout << b2 << endl; // b2는 RefRetFuncOne 값(value)만 리턴받기 떄문에 b의 참조값과 별개. 다른주소값
    cout << b_ref << endl;
    
    int num1 = 20;
    const int &num_ref1 = num1;
    // int 변수가 const하든 참조자가 const 하든 둘다 값변경이 불가능하다. 하지만 num1가 상수화가 안되어있다면 num1을 통해 값변경가능
    // num_ref1 +=20; ERROR
    num1 += 10;
    cout << num_ref1 << endl;
    // 참조자는 직접 값을 저장할 수 없지만 const 키워드를 사용하면 상수 값을 저장할 수 있다.
    const int& num_ref2 = 30;

    cout << Adder(123,456) << endl;
    
    // 문제 02-2 const포인터와 const참조자 90p
    const int num = 12;
    const int* ptr = &num;
    const int *(&ref) = ptr;

    cout << *ref << endl;
    */

    //new delete 키워드
    /*
    char* str1 = MakeStrAdr_malloc(20); //MakeStrAdr의 malloc를 통해 str 이라는 char형 포인터에 char 타입 크기 * 20 만큼을 크기 할당
    char* str2 = MakeStrAdr_malloc(20); // new 키워드를 통해 크기할당
    strcpy(str1, "i am so happy~"); //str char형에 문자열을 쪼개 배열에 저장
    strcpy(str2, "i am so unhappy~"); //str char형에 문자열을 쪼개 배열에 저장
    cout << str1 << endl;
    cout << str2 << endl;
    free(str1); //메모리 소멸
    delete []str2;

    //new는 할당할떄 생성자와 소멸자를 호출하지만 malloc는 호출하지 않는다.
        
    cout << "case1 : ";
    Simple* sp1 = new Simple;
    cout << "case2 : ";
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);
    
    delete sp1;
    free(sp2);
    
    int* ptr = new int;
    *ptr = 20;
    int& ref = *ptr;
    cout << *ptr << endl;
    ref = 15;
    cout << *ptr << endl;
    delete ptr;
    cout << *ptr << endl; //delete 로 힙메모리 제거 했으니 오류값 출력
    */
    //구조체에 대한 new delete 문제 02-3 95p
    /*
    Point* pnt1 = new Point;
    pnt1->xpos = 11;
    pnt1->ypos = 22;
    Point* pnt2 = new Point;
    pnt2->xpos = 31;
    pnt2->ypos = 52;
    
    Point& pref = PntAdder(*pnt1, *pnt2);

    cout << "xpos : " << pref.xpos << endl;
    cout << "ypos : " << pref.ypos << endl;
    
    delete pnt1,pnt2;
    */
    char* str1 = new char[30];
    char* str2 = new char[30];
    char str3[30];

    strcpy(str1, "ABC 123 ");
    strcpy(str2, "DEF 567 ");
    
    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;

    strcpy(str3, str1);
    strcat(str3, str2);

    cout << str3 << endl;
    cout << strlen(str3) << endl;

    //strcmp 는 두 문자열이 같으면 0 다르면 -1 출력
    cout << strcmp(str1, str2) << endl;
    if (strcmp(str1, str2) == 0) {
        cout << "문자열 같음" << endl;
    }
    else{
        cout << "문자열 다름" << endl;
    }

    srand(time(NULL));
    float d;
    for (int i = 0; i != 5; i++) {
        //rand() % 100 + 1 은 0~100까지 출력 + 1안하면 99까지 랜덤 
        printf("Random number #%d: %d\n", i, rand() % 100 + 1);
    }
    for (int i = 0; i != 5; i++) {
        d = (float)(rand() % 100 + 1) / 10;
        printf("실수 테스트 #%d: %.2f\n", i, d);
    }

    cout << "\n end of main \n";
}
