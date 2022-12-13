#include <iostream>

using namespace std;

int main()
{

    union MyUnion{
        /*Usa la stessa regione della memoria per vari tipi di dati
          lultimo ad aquisire un nuovo valore, riscriver quella regione della memoria*/
        int a;
        float b;
        char s;
    };
    MyUnion df;

    df.b = 2.65;
    df.a =876;
    df.s = 't';

    cout << "\n\nb: " << df.b << endl;
    df.a =876;
    cout << "\n\na: " << df.a << endl; // 'a' va a sovrascrivere 'b'
    cout << "\n\ns: " << df.s << endl; // 's' va a sovrascrivere 'a'

}
