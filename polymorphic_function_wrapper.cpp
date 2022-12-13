
#include <iostream>
#include <functional>

using namespace std;

void foo()
{
    cout << "foo function\n";
}

int add(int a, int b)
{
    return a + b;
}


int DoSomethink(int n, int n2, function<int(int, int)> fnc)
{
    cout << "result from polimorphic function: " << fnc(n, n2) << endl;
    cout << "from dosomethink  " << n << " \n";
    return n * 34;
}

int main()
{
    foo();
    // function<"type return"("type data", "type data", ...)> "nome della variabile"
    function<void()> f;
    function<int(int, int)> a;
    f = foo;
    f();
    a = add;
    cout << a(45, 67) << endl;
    DoSomethink(65, 89, a);
    return 0;
}
