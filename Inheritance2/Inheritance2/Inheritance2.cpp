#include <iostream>
#include <cstring>
using namespace std;

//유도클래스 객체참조
/*
class Person
{
public:
    void Sleep()
    {
        cout << "Sleep" << endl;
    }
};
class Student : public Person
{
public:
    void Study()
    {
        cout << "Study" << endl;
    }
};
class PartTimeStudent : public Student
{
public:
    void Work()
    {
        cout << "Work" << endl;
    }
};
*/
//함수 오버라이딩 가상함수
//가상함수를 설정하면 그 함수에 대해서는 기존클래스 변수에 유도클래스 변수를 참조하여 가장 마지막에 오버라이딩 할때 유도클래스의 함수를 사용한다. 
//ex GetPay() 함수 맨 마지막 상속받은 클래스의 오버라이딩 호출
class Employee
{
private:
    char name[100];
public:
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name : " << name << endl;
    }
    //virtual int GetPay() const {
    //    return 0;
    //}
    //순수 가상함수를 하게된다면 해당 클래스는 객체를 못만들고 공통점을 상속만 시켜주는 추상 클래스가 되며 순수가상함수는 무조건 오버라이딩 해줘야한다.
    //ex) main에 Employee* emp = new Employee("test"); 같은 객체를 못만듬
    virtual int GetPay() const = 0; // 순수 가상함수
    virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee 
{
private:
    int salary; // 월급여
public:
    PermanentWorker(const char* name, int money) : Employee(name), salary(money)
    {
        cout << name << " PermanentWorker 생성자" << endl;
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "Salary : " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime; //일한 시간
    int payPerHour; // 시간당 급여
public:
    TemporaryWorker(const char* name, int pay) : Employee(name), payPerHour(pay)
    {
        workTime = 0;
    }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime*payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "Salary : " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult; // 월 판매실적
    double bonusRatio; // 상여금 비울
public:
    SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {
    }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const // 오버라이딩
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const // 재정의를 해주지 않으면 PermanentWorker의 ShowSalaryInfo가 나오기 때문에 오버라이딩을 해준다.
    {
        ShowYourName();
        cout << "Salary : " << GetPay() << endl << endl;
    }
};
// 문제 08-1
namespace{
    enum RISK_LEVEL {
        RISK_A = 30, RISK_B = 20, RISK_C = 10
    };
}
class ForeignSalesWorker : public SalesWorker {
private:
    
    int RISK_LEVEL;
public:
    ForeignSalesWorker(const char* name, int money, double ratio, int risk) : SalesWorker(name, money, ratio), RISK_LEVEL(risk)
    {}
    int GetPay() const
    {
        return SalesWorker::GetPay() + GetRiskPay();
    }
    int GetRiskPay() const
    {
        return (int)(SalesWorker::GetPay() * (RISK_LEVEL / 100.0));
    }
    void ShowSalaryInfo() const // 재정의를 해주지 않으면 PermanentWorker의 ShowSalaryInfo가 나오기 때문에 오버라이딩을 해준다.
    {
        ShowYourName();
        cout << "Salary : " << SalesWorker::GetPay() << endl;
        cout << "risk pay : " << GetRiskPay() << endl;
        cout << "sum : " << GetPay() << endl <<endl;
    }
};
//
class EmployHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployHandler() : empNum(0)
    {
    }
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout << "salary sum : " << sum << endl;
    }
    ~EmployHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
        
    }
};


int main()
{
    //기초 클래스는 유도클래스를 받을 수 있지만 기초클래스 함수만 사용 가능하다.
    //유도클래스는 기초클래스를 참조할 수 없다. 에러발생
    /*
    Person* person = new Student();
    Person* person2 = new PartTimeStudent();
    Student* student = new PartTimeStudent();
    // PartTimeStudent Student2 = new Student(); //error
    person->Sleep();
    person2->Sleep();
    student->Study();
    */  
    //함수 오버라이딩 가상함수
    
    EmployHandler handler;
    ////직원 등륵
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    //addEmployee의 매개변수는 Employee로 되어있지만 ParmanentWorker 는  Employee의 유도클래스 이므로 가능하다.

    //// 임시직 등륵
    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5); // 5시간 일함
    handler.AddEmployee(alba);

    //// 영업직 등륵
    SalesWorker* seller = new SalesWorker("hong", 1000, 0.1);
    seller->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(seller);

    
   
    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    std::cout << "\nEnd of Main\n";
}