#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
#include <vector>
using namespace std;
#include "r_header.h"

/*
Ключевое слово typedef позволяет программисту создать псевдоним для любого
типа данных и использовать его вместо фактического имени типа.
*/

void typedef_foo(){
    typedef double time_t; // используем time_t в качестве псевдонима для типа double
    /*praticamente abbiamo cambiato il nome double in time_t
    "time_t" non e` una variabile ma un identificatore*/

    // Следующие два стейтмента эквивалентны
    double howMuch1;
    time_t howMuch;

    // используем pairlist_t в качестве псевдонима для этого длиннющего типа данных
    typedef std::vector<std::pair<std::string, int>> pairlist_t;
    pairlist_t pairlist; // объявляем pairlist_t


    // Следующий typedef:
    typedef double time_t; // используем time_t в качестве псевдонима для типа double
    // В С++11 можно объявить как:
    using time_t2 = double; // используем time_t2 в качестве псевдонима для типа double
    // Эти два способа функционально эквивалентны.
}

using weigth = double;
typedef string name;

name ask(){
    return "masha";
}

weigth foo(double x){
    return x * x;
}




int main(){
    cout << "\n\n\n" << foo(3.45) << "   " << ask() << "\n\n\n";
    return 0;
}



