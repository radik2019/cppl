#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"

class Car
{
private:
    static int id_count;
    int id_;
    int speed;
    int weight;
    string name;
    string model;

public:
    Car(
        int speed, int weight, string name, string model);
    Car();
    ~Car();

    static int getIdCount()
    {
        return Car::id_count;
    }
    static void changeName(Car &obj, string newName)
    {
        obj.name = newName;
    }
    void info()
    {   cout << "\n";
        cout << "Name: \t" << this->name << endl;
        cout << "model:\t" << this->model << endl;
        cout << "Pointer:\t" << this << endl;
        cout << "id:   \t" << this->id_ << endl;
        cout << "speed:\t" << this->speed << endl;
        cout << "weigt:\t" << this->weight << endl;
        cout << "Count Id:\t" << Car::id_count << endl;
        cout << "\n";
    }
};

Car::Car(int speed, int weight, string name, string model)
{
    this->model = model;
    this->name = name;
    this->speed = speed;
    this->weight = weight;
    this->id_ = ++Car::id_count;
    cout << "Created obj with id: \"" << this->id_ << "\" \n";
}

Car::Car()
{
    this->model = "NoModel";
    this->name = "NoName";
    this->speed = 0;
    this->weight = 0;
    this->id_ = ++Car::id_count;
    cout << "Created obj with id: \"" << this->id_ << "\" \n";
}

Car::~Car()
{
    cout << "removed obj with id: \"" << this->id_ << "\"\tPointer:\t" << this << " \n";
}

int Car::id_count = 0;

int main()
{
    Car n1(234, 1789, "BMW", "356");
    Car n2{237, 1456, "Audi", "A4"};
    Car n3;
    Car::changeName(n3, "newChangedName");
    Car n4(342, 1678, "Ferrari", "Enzo");
    cout << "count id " << Car::getIdCount() << endl;

    n1.info();
    n2.info();
    n3.info();
    n4.info();

    return 0;
}
