
#include "r_header.h"

class Car
{
private:
    unsigned int car_speed;

public:
    Car(int sp)
    {
        this->car_speed = sp;
    }
    ~Car()
    {
        cout << "\nCar destructor\n";
    }
    int getSpeed()

    {
        cout << "\ngetSpeed from Car\n\n";
        return this->car_speed;
    }
};

class Plane
{
protected:
    int plane_speed;

public:
    Plane(int sp)
    {
        this->plane_speed = sp;
    }
    ~Plane()
    {
        cout << "\nPlane destructor\n";
    }
    int getSpeed()
    {
        cout << "\ngetSpeed from Plane\n";
        return this->plane_speed;
    }
};

class CarPlane : public Car, public Plane
{
private:
    int carplane_Speed;

public:
    CarPlane(int sp, int x, int y) : Car(x), Plane(y)
    {
        this->carplane_Speed = sp;
    }
    ~CarPlane()
    {
        cout << "\nCarPlane destructor\n";
    }
    void info()
    {
        cout << "Car:  \t" << ::Car ::getSpeed() << endl;
        cout << "Plane:\t" << ::Plane ::getSpeed() << endl;
    }
};

int main()
{
    CarPlane crpl(23, 34, 567);
    // crpl.info();
    (Plane(crpl)).getSpeed();


    return 0;
}
