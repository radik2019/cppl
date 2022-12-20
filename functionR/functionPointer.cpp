
#include <iostream>
using namespace std;

/*il pointer della funzione punta sull`indirizzo
del codice*/

void foo(int *num){
    cout << "\n\n**  "<< *num<<"  function \n\n";
}


void someFunc(int *dor, void (*func)(int *num)){
    /*qui la funzione si aspetta come argomenti 
    un puntatore per un int
    e un puntatore per una funzione che ritorna void e ha come argomenti
    un ountatore int*/
    cout << "From \"someFunc\":  " << endl;
    func(dor);
}


int main()
{
    void (*doo)(int *h) = foo;
    int num = 999;
    int *pnum = &num;

    /*i due statement sotto sono uguali*/
    doo(pnum); 
    (doo)(pnum);


    someFunc(pnum, doo);

    
    return 0;
}
