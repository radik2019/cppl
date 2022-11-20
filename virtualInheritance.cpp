
#include <iostream>
using namespace std;

class A
{
private:
    /* data */
public:

    A()
    {
        cout << "Constructor A\n";
    }

    ~A()
    {
        cout << "Destructor A\n";
    }
};

class B: virtual A
{
private:
    /* data */
public:

    B(): A()
    {
        cout << "Constructor B\n";
    }

    ~B()
    {
        cout << "Destructor B\n";
    }
};

class C: virtual A
{
private:
    /* data */
public:

    C(): A()
    {
        cout << "Constructor C\n";
    }

    ~C()
    {
        cout << "Destructor C\n";
    }
};

class X: public B, public C
{
private:
    /* data */
public:

    X(): C(),  B()
    {
        cout << "Constructor X\n";
    }

    ~X()
    {
        cout << "Destructor X\n";
    }
};


int main(){
    X df;
}

/*
                    A
                  /  \
                 /    \
(virtual A)--> B       C <-- (virtual A) 
                \     /    
                 \  /   
                  X  

L`eredita' multipla romboidale porta alla chiamata
dello stesso costructor e destructor (A) piu` volte dall'istanza (X)
per evitare cio`, nelle classi B e C si eredita da A in modo virtuale   

*/