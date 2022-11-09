

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
        this->size = size;
        for (int i = 0; i < size; i++){
            this->lst[i] = 1111 * this->size;
        }  
    }

    ~ListR(){
        delete[] this->lst;
        cout << this << "  lst deleted\n\n\n\n";
    }

    ListR(ListR &other){
        // Creo la copia della lista
        this->lst = new  int[size];
        this->size = other.size;
        for (int i = 0; i < other.size; i++){
            this->lst[i] = other.lst[i];
        }
        cout << "\n\n++ copied ++  " << &other << " on " << this << endl;
    }

    void operator = (ListR &other){
        /*
        Operator Overloading "="
        */
        delete[] this->lst;
        this->lst = new int[other.size];
        this->size = other.size;
        if (other.lst != nullptr){
            for (int i = 0; i < other.size; i++){
                this->lst[i] = other.lst[i];
            }
        }
    }

    void info(){
        print();
        print(this);
        print(this->lst, this->size);
        print();
    }

    int* get_lst(){
        return this->lst;
    }

    void setData(int index, int value){
        cout << "set data:   " << this->lst << endl;
        this->lst[index] = value;
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


    Vehicle(int whelsValue, int speedValue, string nameValue){
        // Constructor
        // Deve essere "public"
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


    Vehicle(const Vehicle &other){
        /*
        Constructor copi
        andiamo a copiare i dati dall'"other" al "this"
        */
        this->name = other.name;
        this->speed = other.speed;
        this->whels = other.whels;

    }

    /***************************************************/
    // Destructor. Puo` essere solo uno
    // e non puo` avere parametri
    ~Vehicle(){
        cout << "Destructor:\t" << this->name << "  " << this << endl;
    }
    /***************************************************/
    void info(){
        cout << "\t\tinfo\n";
        cout << "whels:\t" << this->whels << endl;
        cout <<"speed:\t" << this->speed << endl;
        cout <<"name:\t" << this->name << endl;
    }

    void setWhels(int value){
        this->whels += value;
    }
    void setName(string value){
        this->name += value;
    }
    void setSpeed(int value){
        this->speed += value;
    }
};

Vehicle foo(Vehicle obj){
    obj.info();
    return obj;
    
}

int main () {

    ListR mylist(3);
    
    ListR ownList(7);




    ownList.setData(0, 9999);
    mylist.info();

    ownList.info();
    mylist = ownList;

    print("--------------------------------------");
    
    mylist.setData(2 , 123456);
    mylist.info();

    ownList.info();
    /*
    Vehicle lst2(4, 453, "Bugatti"); //Crea instanza
    Vehicle oslo(lst2); // Crea la copia dell'instanza
    oslo.setWhels(6);
    oslo.setName("_Veiron");
    oslo.setSpeed(-167);
    */


    print();
    return 0;
}


