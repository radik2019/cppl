

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"


int my_rand(int){
    return (82039 * 24543) % 100;
}

int main () {
    cout << my_rand(43) << endl;
    return 0;
    
}



