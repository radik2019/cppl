#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"


class Pc
{
public:
    enum PcState
    {
        OFF,  // = 0
        ON,   // = 1
        SLEEP // = 2
    };
    void setState(PcState state){this->state = state;}
    PcState getState(){return this->state;}
private:
    PcState state;
};

void test2()
{
    // PcState st;
    // st = PcState::ON;
    Pc pc;
    pc.setState(Pc::PcState::ON);
    if (pc.getState() == Pc::PcState::OFF){cout << "Il pc e` spento\n";}
    else if (pc.getState() == Pc::PcState::ON){cout << "Il pc e` attivo\n";}
    else if (pc.getState() == Pc::PcState::SLEEP){cout << "Il pc e` in ibernazione\n";}
}

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

int test1()
{
    int a = 0;
    if (static_cast<int>(Colors::PINK) == a) // per paragonarli bisogna prima modificare il tipo
    {
        print("uguale");
    }

    // print(GRAY); // error

    return 0;
}

int main()
{
    test2();
}
