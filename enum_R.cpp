#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"

enum Sound
{
    TIC,
    TOC,
    MOK = 10,
    CIOC,
    LOK
};

enum class Colors
{
    PINK, // PINK находится внутри той же области видимости, что и Colors
    GRAY
};

int main()
{
    int a = 0;
    if (static_cast<int>(Colors::PINK) == a) //per paragonarli bisogna prima modificare il tipo
    {
        print("uguale");
    }

    // print(GRAY); // error

    return 0;
}
