

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"


void foo(int &value){
    value += 30;
}

void foo(int* value){
    *value += 10;
}

int main () {
    string name, name2;
    cout << "inserire il numero: ";
    cin >> name2 ;
    // cin.ignore(32767, '\n');

    cout << "Come ti chiami?: ";
    getline(cin, name);
    cout << "tu ti chiami: " << name << "!" << endl;
    
    return 0;
    
}



