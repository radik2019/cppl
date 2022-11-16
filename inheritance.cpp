
#include "r_header.h"

class Human
{
public:
    string name = "Boris";

private:
    string birthday = "12,1, 2012";

protected:
    string brain = "brain";
};

class Student : public Human
{
public:
    string group = "Gruppa VI";

    void info()
    {
        cout << "\n\n";
        cout << this->brain << endl; // Protected
        cout << this->name << endl;
    }
};

class Developer : private Human
{
public:
    void info()
    {
        cout << 11111111 << this->brain << endl;
    }
};

/////////////////      CONSTRUCTOR CLASS    //////////////////////

class Abstract
{
public:
    virtual void info() = 0;
    virtual ~Abstract(){
        cout << "\nDestructor Abstract - " << "\n\n";
    }
};

class A : public Abstract
{
public:
    int a;
    A()
    {
        cout << "\nConstructor A default \n\n";
    }
    A(int a)
    {
        this->a = a;
        cout << "\nConstructor A - " << this->a << "\n\n";
    }
    ~A() override { cout << "\nDestructor A\n\n"; }

    void info() override
    {
        cout << "\ni overriding a info from Abstract class B \n";
        cout << "int a = " << this->a << "\n\n";
    }
};

class B : public A
{
public:
    int b;
    B() : A()
    {
        cout << "\nConstructor B default\n\n";
        this->b = 0;
    }
    B(int b, int a) : A(a)
    {
        this->b = b;
        cout << "\nConstructor B - " << this->b << "\n\n";
    }
    ~B() { cout << "\nDestructor B\n\n"; }
    void info() override
    {
        cout << "\ni overriding a info from Abstract class B \n";
        cout << "int a = " << this->a << "\n";
        cout << "int b = " << this->b << "\n\n";
    }
};

/////////////////      END CONSTRUCTOR CLASS    //////////////////////

int main()
{
    B val(2, 3);
    // A val2;
    val.info();
    // val2.info();
    print("===============================================");
    return 0;
}
