

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>

using namespace std;
#include "r_header.h"

int main()
{

    print("\n\n\n\n");

    string fg = "7654.365698";
    print(to_doublee(fg));
    print();
    print(to_doublee(fg) + 0.00698);

    print("\n\n\n\n");
    return 0;

}
