#include <iostream>
using namespace std;

// 대입연산자 오버로딩 (자주쓰임)
// 상속받을때 AAA num =ref; 같이 명시적으로 하면 AAA의 생성자와 대입연산자가 생성되지만 
// 이니셜라이저를 사용하여 초기화하면 복사생성자만 호출되어 좀더 효율적이다.

class First
{
private:
    int num1, num2;
public:
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    {
    }
    void ShowData()
    {
        cout << num1 << ", " << num2 << endl;
    }
    
};

class Second
{
private:
    int num3, num4;
public:
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
    {
    }
    void ShowData()
    {
        cout << num3 << ", " << num4 << endl;
    }
    Second& operator=(const Second& ref)
    {
        cout << "Second& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this; // int& ref = *ptr 생각하면됨 리턴값이 &(참조)
    }
};
//상속된 클래스로 대입연산자를 사용하게 되면 기초클래스의 대입연산자는 명시적으로 해주지 않으면 복사대상에서 제외된다.
class Third : public Second
{
private:
    int num5, num6;
public:
    Third(int n3=0, int n4=0, int n5 = 0, int n6 = 0) : num5(n5), num6(n6), Second(n3,n4)
    {
    }
    void ShowData()
    {
        Second::ShowData();
        cout << num5 << ", " << num6 << endl;
    }
    
    Third& operator=(const Third& ref)
    {
        cout << "Third& operator=()" << endl;
        Second::operator=(ref); // 명시적으로 대입연산자 사용을 해주지 않으면 Second 부분은 복사되지않는다.
        num5 = ref.num5;
        num6 = ref.num6;
        return *this; // int& ref = *ptr 생각하면됨 리턴값이 &(참조)
    }
    
};
//대입연산자의 문제점 : char* 형을 복사 후 delete를 하게 되면 얉은복사가 되어 메모리 소멸에 문제와 
// 문자열의 크기만큼 할당되는 char*형 이기 떄문에  문자열 크기의 문제가 생기기도 한다.
//이를 해결하기 위해서는 깊은 복사를 하여 메모리 공유문제를 해결하고 전에 있던 메모리를 먼저 할당 해제후 복사할 문자열 크기만큼 재할당 해준다.
class Person
{
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage) : age(myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
    }
    void Showinfo()
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~Person()
    {
        delete[] name;
        cout << "소멸자 실행" << endl;
    }
    Person& operator=(const Person& ref)
    {
        delete[] name;
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
};
//문제 11-1
class Gun
{
private:
    int bullet; // 총알갯수
public:
    Gun(int num) : bullet(num) {}
    void Shot()
    {
        cout << "BBANG" << endl;
        bullet--;
    }
};
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
        if(handcuffs>0)
        {
            cout << "잡았다" << endl;
            handcuffs--;
        }
        else
            cout << "수갑 부족" << endl;
    }
    ~Police()
    {
        if (pistol != NULL)
        {
            delete pistol;
        }
    }
    Police(const Police& ref) : handcuffs(ref.handcuffs) // 복사생성자 (변수를 선언과 동시에 대입하는경우) ex) police man1 = man2;
    {
        if (ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol)); //Gun 안의 값을 확인
        else
            pistol = NULL;
    }
    Police& operator=(const Police& ref) //대입연산자  (변수를 선언한 이후 복사하는경우 ex) police man1; man1 = man2;
    {
        if (pistol != NULL)
            delete pistol;
        if (ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol)); //Gun 안의 값을 확인
        else
            pistol = NULL;
        handcuffs = ref.handcuffs;
        return *this;
    }
};
//문제 11-1 2번
class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* book_title, const char* book_isbn, int book_price) : price(book_price)
    {
        title = new char[strlen(book_title) + 1];
        isbn = new char[strlen(book_isbn) + 1];
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
    Book(const Book& ref) : price(ref.price)
    {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.title);
    }
    Book& operator=(const Book& ref)
    {
        delete[] title;
        delete[] isbn;

        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
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
    EBook(const EBook& ref) : Book(ref)
    {
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);
    }

    EBook& operator=(const EBook& ref)
    {
        delete[] DRMkey;

        Book::operator=(ref);
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);

        return *this;
    }
};
int main()
{
    //대입연산자 오버로딩
    
    First fsrc(111, 222);
    First fcpy;

    Second ssrc(333, 444);
    Second scpy;

    fcpy = fsrc;
    scpy = ssrc;

    fcpy.ShowData();
    scpy.ShowData();

    First fob1, fob2;
    Second sob1, sob2;
    fob1 = fob2 = fsrc;
    sob1 = sob2 = ssrc;
    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();
   
    cout << endl << endl;
    //대입연산자의 문제점
    Person man1("LEE", 29);
    Person man2("YOON", 22);
    man2 = man1;
    man1.Showinfo();
    man2.Showinfo();

    cout << endl << endl;
    //상속 대입연산자
    Third test1(11, 22, 33, 44);
    Third test1_cpy(0, 0, 0, 0);
    test1_cpy = test1;
    test1_cpy.ShowData();

    cout << endl << endl;
    //문제 11-1 1번
    Police pman1(2, 1); //총알 5개 수갑3개
    Police pman2 = pman1; // 복사생성자로 pman1의 갯수 그대로 복사
    pman2.Shot();
    pman2.PutHandcuff();

    cout << endl;
    Police pman3(2,4);
    pman3 = pman1; // 대입연산자로 복사
    pman3.PutHandcuff();
    pman3.PutHandcuff();

    cout << endl;
    //문제 11-1 2번
    EBook ebook1("좋은 c++ ebook", "555-12345-123-1", 10000, "fdxg214gerwe");
    EBook ebook2 = ebook1; //복사생성자
    ebook2.ShowEBookInfo();
    cout << endl;

    EBook ebook3("null", "null", 0, "null");
    ebook3 = ebook2;
    ebook3.ShowEBookInfo();

    std::cout << "\nEnd Of Main\n";
}