#include "r_header.h"

class DelegConstr
{
private:
    int age;
    string name;
    string gender;
public:
    DelegConstr();
    DelegConstr(int age);
    DelegConstr(int age, string name);
    DelegConstr(int age, string name, string gender);
    ~DelegConstr();

    void info(){
        cout << "\n\nAge:  \t" << this->age << endl;
        cout << "Name:  \t" << this->name << endl;
        cout << "Gender:\t" << this->gender << "\n\n";
    }
};


DelegConstr::DelegConstr()
{
    this->age = 0;
    this->name = "noName";
    this->gender = "noGender";
}

DelegConstr::DelegConstr(int age)
{
    this->age = age;
    this->name = "noName";
    this->gender = "noGender";
}

DelegConstr::DelegConstr(int age, string name): DelegConstr(age)
{
    this->name = name;
    this->gender = "noGender";
}

DelegConstr::DelegConstr(int age, string name, string gender): DelegConstr(age, name)
{
    this->gender = gender;
}


// DelegConstr::~DelegConstr()
// {
// }



int main(){
    DelegConstr df(23);
    DelegConstr df1(23, "Mark");
    DelegConstr df2(23, "Ivan", "Male");
    DelegConstr df3;

    df.info();
    df1.info();
    df2.info();
    df3.info();
    

    return 0;
}
