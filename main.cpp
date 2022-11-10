

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

void foo2(int* value){
    *value += 10;
}

int main () {
    int s = 1;
    int *ps = &s;
    foo2(ps);
    cout << s <<  "\n\nhello world\n\n\n";

    return 0;
}



