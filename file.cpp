
#include <iostream>
#include <string>

#define LINE cout << "\n------------------\n"
#ifdef LINE
#define HORSE = cout << "cavallo\n"
#endif


using namespace std;

class Car{
    public:
        string carName;

    public:
        int horsePower;

    public:
        void setName(string x, int y){
            carName = x;
            horsePower = y;
        };

    public:
        void getName(){
            
            cout << "\ncar name            " << carName;
            cout << "\nhorse power         " << horsePower;
        };
};

int main(){
    Car bmw;
    bmw.setName("bmw", 380);
    bmw.getName();

    Car audi;
    audi.setName("audi", 352);
    LINE;
    audi.getName();
    LINE;

    return 0;
}

