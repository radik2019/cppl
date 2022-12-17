
#include <iostream>
#include <functional>

using namespace std;


int add(int a, int b)
{

    return a + b;
}

int quad(int num)
{
    return num * num;
}

void to_cube(int *lst, const int len, function<int(int)> func)
{
    for (int i = 0; i < len; i++)
    {
        lst[i] = func(lst[i]);
    }
}

int main()
{
    int lok = 333;
    int lst[] = {33, 65, 18, 62, 48, 90, 19};
    function<int(int)> func;
    func = quad;
    to_cube(lst, 7, func);

    /*per axcceder a una variabile globale dalla funzione lambda
    si devono dichiarare nelle parentesi quadrate []*/
    to_cube(lst, 7, [lok](int x)
            { return x + lok; });
    for (int &item : lst)
    {
        cout << "*  " << item << ", ";
    }
    cout << "\n\n";

    return 0;
}
