
#include "r_header.h"

class ListR
{
private:
    int *lst;
    int size;

public:
    ListR()
    {
        this->lst = new int[1];
        this->size = 1;
    }

    ListR(int size)
    {
        this->lst = new int[size];
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            this->lst[i] = 0;
        }
    }

    ~ListR()
    {
        delete[] this->lst;
        cout << this << "  lst deleted\n";
    }

    ListR(ListR &other)
    {
        // Creo la copia della lista
        this->lst = new int[size];
        this->size = other.size;
        for (int i = 0; i < other.size; i++)
        {
            this->lst[i] = other.lst[i];
        }
        cout << "\n\n++ copied ++  " << &other << " on " << this << endl;
    }

    ListR &operator=(ListR &other)
    {
        /*
        Operator Overloading "="
        */
        cout << &other << "     ====>     " << this << endl;
        delete[] this->lst;
        this->lst = new int[other.size];
        this->size = other.size;
        if (other.lst != nullptr)
        {
            for (int i = 0; i < other.size; i++)
            {
                this->lst[i] = other.lst[i];
            }
        }
        return *this;
    }

    bool operator==(const ListR &other)
    {
        if (this->size == other.size)
        {
            bool flag = true;
            for (int i = 0; i < this->size; i++)
            {
                if (this->lst[i] != other.lst[i])
                {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        return false;
    }

    bool operator!=(const ListR &other)
    {
        if (this->size = other.size)
        {
            bool flag = true;
            for (int i = 0; i < this->size; i++)
            {
                if (this->lst[i] != other.lst[i])
                {
                    flag = false;
                    break;
                }
            }
            return !flag;
        }
        return true;
    }

    ListR operator+(const ListR &other)
    {
        ListR tempr(this->size + other.size);
        for (int i = 0; i < this->size; i++)
        {
            tempr.lst[i] = this->lst[i];
        }
        for (int i = 0; i < other.size; i++)
        {
            tempr.lst[this->size + i] = other.lst[i];
        }
        tempr.size = this->size + other.size;
        return tempr;
    }

    int &operator[](int index)
    {
        if (index >= this->size)
        {
            print("Out of range index!   ");
            return this->lst[0];
        }
        return this->lst[index];
    }

    void info()
    {
        print("------------------------------------------------");
        print(this);
        print(this->size);
        print(this->lst, this->size);
        print("------------------------------------------------");
    }

    int *get_lst()
    {
        return this->lst;
    }

    void setData(int index, int value)
    {
        cout << "set data:   " << this->lst << endl;
        this->lst[index] = value;
    }
};
class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(Point &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    Point operator++()
    {
        this->x++;
        this->y = y + 1;
        return *this;
    }
    Point operator++(int value)
    {
        Point temp = *this;
        ++this->x;
        ++this->y;
        return temp;
    }

    int getX()
    {
        return this->x;
    }
    friend void work_of_Point(Point &object);
};

void work_of_Point(Point &object)
// friend function
{
    object.x = object.x + object.y;
    print(object.x);
}

void work_of_ListR()
{
    ListR mylist(4);
    ListR mylist2(7);
    mylist.setData(0, 121);
    mylist.setData(1, 121);
    mylist[3] = 79811;
    mylist.setData(3, 121);
    // mylist2.setData(, 456);
    mylist2[1] = 890;
    mylist2[2] = 12903;
    mylist2[3] = 456;
    mylist2.info();
    mylist.info();
    ListR ownList = (mylist + mylist2);
    ownList[3] = 9000;
    cout << (mylist2 == mylist) << endl;
    // mylist2.info();
    // mylist.info();
    ownList.info();

    // mylist.info();
    // ownList.info();

    // print("--------------modifica--------------");
    cout << ownList[3] << endl;
    // mylist.setData(1, 1);
    // mylist.info();
    // ownList.info();
}

class Vehicle
{

    // public:
protected:
    // private:
    int whels{4};
    int speed{300};
    string name{"bmwM5"};

public:
    Vehicle(int whelsValue, int speedValue, string nameValue)
    {
        // Constructor
        // Deve essere "public"
        if (whelsValue > 4)
        {
            nameValue += "_Truck";
            cout << "Is a truck!!\n";
        }
        whels = whelsValue;
        speed = speedValue;
        name = nameValue;
    }

    Vehicle()
    {
        whels = 0;
        speed = 0;
        name = "no Name";
    }

    Vehicle(const Vehicle &other)
    {
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
    ~Vehicle()
    {
        cout << "Destructor:\t" << this->name << "  " << this << endl;
    }
    /***************************************************/
    void info()
    {
        cout << "\t\tinfo\n";
        cout << "whels:\t" << this->whels << endl;
        cout << "speed:\t" << this->speed << endl;
        cout << "name:\t" << this->name << endl;
    }

    void setWhels(int value)
    {
        this->whels += value;
    }
    void setName(string value)
    {
        this->name += value;
    }
    void setSpeed(int value)
    {
        this->speed += value;
    }
};

void work_of_Vehicle()
{
    Vehicle bugatti(4, 453, "Bugatti"); // Crea instanza
    Vehicle veiron(bugatti);            // Crea la copia dell'instanza
    veiron.setWhels(6);
    veiron.setName("_Veiron");
    veiron.setSpeed(-167);
}

int main()
{

    // work_of_Point();
    work_of_ListR();

    return 0;
}
