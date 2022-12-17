#include "r_header.h"
#include <exception>



void test(){
    vector<int> lst2  = {3, 8, 12, 6};
    vector<int>::iterator lst;
    lst = lst2.begin();
    cout << *lst << endl;
    ++lst;
    cout << *lst << endl;
    cout << *lst << endl;
    cout << *lst << endl;
}



void test2(){
    vector<int> lst = {3, 0, 12, 6};
    

    for (vector<int>::iterator i = lst.begin(); i != lst.end(); i++)
    /*si crea l'iteratore "i" dandoli il puntatore del primo elemento "lst.begin()
    il ciclo for continuera` finche`non trovera' il puntatore del "lst.end() che indicherebbe
    a un NONdato" 
    "*/
    {
        /*usando "::iterator", abbiamo il diritto di modificare il dato*/
        if (*i % 2 == 0)
        {
            *i = *i+0;
        }
        cout << *i << endl;
        
    }

    for (vector<int>::const_iterator i = lst.cbegin(); i != lst.cend(); i++)
    /*si crea l'iteratore "i" dandoli il puntatore del primo elemento "lst.begin()
    il ciclo for continuera` finche`non trovera' il puntatore del "lst.end() che indicherebbe
    a un NONdato" 
    "*/
    {
        cout << *i << "  -   ";
        /*usando "::const_iterator", NON abbiamo il diritto di modificare il dato
        e` in modalita` di sOlo LETTURA*/
        try
        {
            cout << "  +   "<< (7 / *i /8) << endl;
            // i = *i+100;//  NON SI PUO'

        }

        catch (...)
        {
            cout << "I dati non si possono modificare" << '\n';
        }      
    }
    
}



int main()
{
    test2();
    return 0;
}

















