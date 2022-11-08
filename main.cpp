

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"

class Vehicle{
    
// public:
protected:
// private:
    int whels {4};
    int speed{300};
    string name{"bmwM5"};
public:

    // Constructor
    // Deve essere "public"
    Vehicle(int whelsValue, int speedValue, string nameValue){
        if (whelsValue > 4){
            nameValue += "_Truck";
            cout << "Is a truck!!\n";
        }
        whels = whelsValue;
        speed = speedValue;
        name = nameValue;
    }

    Vehicle(){
        whels = 0;
        speed = 0;
        name = "no Name";
    }

    void info(){
        cout << "\t\tinfo\n";
        cout << "whels:\t" << this->whels << endl;
        cout <<"speed:\t" << this->speed << endl;
        cout <<"name:\t" << this->name << endl;
    }

    void setter(int w, int s, string n){
        whels = w;
        speed = s;
        name = n;
    }
};


int main () {
    Vehicle bmw(6, 235, "320i");
    Vehicle x; 
    // bmw.setter(6, 235, "320i");
    bmw.info();
    x.info();
    
    return 0;
}



