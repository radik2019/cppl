

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
using namespace std;
#include "r_header.h"



double division(int a, int b) {
    if( b == 0 ) {
        throw "Division by zero condition!";
    }
    return (a/b);
}

int main () {
    print("\n\n\n\n");
    print(to_doublee("234.38.41"));

    print("\n\n\n\n");

    return 0;
}


