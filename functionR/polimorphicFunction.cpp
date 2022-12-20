
#include "../r_header.h"
#include <functional>
using namespace std;

int add(int x){
    return x * 45;
}


int age_to_days(int years){
    return years * 365;
}


void elaborateFunc(int &lst, function<int(int)> foo){
    lst = foo(lst);
}


void test1()
{

    function<int(int)> foo;
    /*qui ho creato un oggetto "function"
    che vale per qualsiasi funzione che ha come argomento un "int"
    e ritorna un "int"*/

    foo  = add; //qui diciamo all`oggetto che deve diventare la funzione "add"
    cout << foo(34) << endl;
    foo = age_to_days; //qui diciamo all`oggetto che deve diventare la funzione "age_to_days"
    cout << "2 anni fanno: "<< foo(2) << " giorni"<< endl;

}


int main()
{
    int lst[]={3, 6, 9};
    cout << "first value from lst: "<< lst[0] << endl;
    function<int(int)> bar;
    bar = age_to_days;
    elaborateFunc(lst[0], bar);
    cout << "first value from lst: "<< lst[0] << endl;
    return 0;
}