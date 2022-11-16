#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"

#define nl "\n\n";

struct Coord{
    double latitude;
    double longitude;
};

struct Home{
    int window;
    double surface;
    int door;
    string city;
    string street;
    Coord pos;
};

void info(Home stru){
    cout << nl;
    cout << "window: \t" << stru.window << endl;
    cout << "surface:\t" << stru.surface << endl;
    cout << "door:   \t" << stru.door << endl;
    cout << "city:   \t" << stru.city << endl;
    cout << "street: \t" << stru.street << endl;
    cout << "position\t" << "(" << stru.pos.latitude << ", " << stru.pos.longitude << ")\n\n";
}

void change_surface(Home &hm){
    hm.surface += 100.0;
}


int main(){
    Home arba;
    arba.surface = 162.12;
    arba.window = 2;
    Home rd{5, 142.3, 4, "New York", "Jhonsons street", Coord{2.34, 5.234}};
    Home rd2{3, 58.3, 4, "Chicago", "Rocky street", {7.40, 52.82}};
    // cout << "\n\n" << rd.surface << "\n" << rd.door<< "\n" << rd.street<< "\n" << rd.city << endl;
    info(rd);
    change_surface(rd);
    info(rd);
    cout << sizeof rd << nl;


    return 0;
}
