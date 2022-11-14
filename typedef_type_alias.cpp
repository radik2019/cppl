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

void foo(){
    typedef double time_t; // используем time_t в качестве псевдонима для типа double
    /*praticamente abbiamo cambiato il nome double in time_t
    "time_t" non e` una variabile ma un identificatore*/

    // Следующие два стейтмента эквивалентны
    double howMuch1;
    time_t howMuch;

    // используем pairlist_t в качестве псевдонима для этого длиннющего типа данных
    typedef std::vector<std::pair<std::string, int>> pairlist_t;
    pairlist_t pairlist; // объявляем pairlist_t
}




int main(){
    return 0;
}



