<<<<<<< HEAD

#include "r_header.h"



int main () {

=======
#include <vector>
#include "r_header.h"



class Human
{
private:
    string date;
    string name;
public:
    Human(string date, string name);
    Human();
    ~Human();
    void setName(string name){this->name = name;}
    void setDate(string date)
    {
        this->date = date;
    }
    string getName(){return this->name;}
    string getDate(){return this->date;}
};

Human::Human(string date, string name)
{
    this->date = date;
    this->name = name;
};

Human::Human()
{
    this->date = "date";
    this->name = "name";
}

Human::~Human()
{
    cout << 222222 << endl;
}


class Profession : public Human
{
private:
    string job;
public:
    Profession(string name, string date, string job);
    ~Profession();
};

Profession::Profession(string name, string date, string job) : Human( date, name)
{
    this->job = job;
    this->setDate(date);
    this->setName(name);
}

Profession::~Profession()
{
    cout << "Destructor of Profession " << this->getName() << endl;
}

bool isDigit(char symbol){
    string numbers = "0123456789";
    for (int i = 0; i < numbers.length(); i++)
    {
        if (numbers[i] == symbol)
        {
            return true;
        }
        
    }
    return false;

}

vector<int> extractDigits(string strNum){
    vector<int> lst;
    string temp = "";
    for (int i = 0; i < strNum.length(); i++)
    {
        if (isDigit(strNum[i]))
        {
            temp += strNum[i];

        }else if (temp != "")
        {
            lst.push_back(to_int(temp));
            temp = "";
        }
    }
    if (temp != ""){
        lst.push_back(to_int(temp));
    }      
    return lst;
}

bool isDay(int day){
    if ((day < 32) && (day > 0))
    {
        return true;
    }
    return false;
}

bool isMonth(int month){
    if ((month < 13) && (month > 0))
    {
        return true;
    }
    return false;
}

bool isYear(int year){
    if ((year < 2020) && (year > 1900))
    {
        return true;
    }
    return false;
}

bool isDate(vector <int> lst){
    if (lst.size() == 3)
    {
        if (!isDay(lst[0])) return false;
        if(!isMonth(lst[1])) return false;
        if(!isYear(lst[2])) return false;
        return true;
    }
    return false;
}

int main () {


    string s = "12 3 2019";
    vector<int> lst = extractDigits(s);
    cout << "\n\n[" << lst[0] << ", " << lst[1] << ", " << lst[2] << "]" << endl;
    if (isDate(lst))
    {
        print("\n\n\nIs DATEEEEEEE\n\n\n");
    }else{
        print("\n\nFail on the date\n\n");
    }
    

>>>>>>> StringClass
    return 0;
}

