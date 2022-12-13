
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
    f = foo;
    f();
    function<int(int, int)> a;
    
    
    function<int(int)> ax;
    ax = [](int x){return x * x;};
    cout << "ax:  " <<  ax(34) << endl;
    
    
    a = add;
    DoSomethink(65, 89, a);
    auto ff {[](int x){return x * x;}};
    auto ff2 {[](){return "helloooooooo";}};
    cout << "ff  "<< ff(9) << endl;
    cout << "ff2  "<< ff2() << endl;


    return 0;
}
