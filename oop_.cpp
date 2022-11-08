

#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"

class ListR{
private:
    int *lst;
    int size;

public:
    ListR(int size){
        this->lst = new  int[size];
        for (int i = 0; i < size; i++)
        {
            this->lst[i] = (i + 23) * 4;
        }
        this->size = size;
        
    }
    ~ListR(){
        delete[] this->lst;
        cout << "lst deleted\n";
    }

    void info(){
        print(this);
        print(this->lst, this->size);
    }

    int* get_lst(){
        return this->lst;
    }
};


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


    /***************************************************/
    // Destructor. Puo` essere solo uno
    // e non puo` avere parametri
    ~Vehicle(){
        cout << "Destructor:\t" << this << endl;
    }
    /***************************************************/
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


Vehicle foo(Vehicle obj){
    cout << "foo-------------\n";
    obj.info();
    return obj;
    
}

int main () {

    Vehicle lst2(4, 453, "Bugatti");
    lst2.info();
    Vehicle oslo = foo(lst2);
    
    return 0;
}


