#include "r_header.h"

// template <typename T>
class SmartPointer
{
private:
    int *ptr;
public:
    static inline int count = 0;
    SmartPointer(int *ptr)
    {
        this->ptr = ptr;
        this->count += 1;
        cout<< *this->ptr << "   Constructor\n\n";
    }
    ~SmartPointer()
    {
        // delete this->ptr;
        cout << "Destructor\n\n";
    }
    int& operator*(){
        return *ptr;
    }

    void info(){
        cout <<"\n\n===================================\n";
        cout << "data:\t" << this->count << endl;
        cout << "data:\t" << this->count << endl;
        cout << "data:\t" << this->count << endl;
        cout <<"===================================\n\n";
    }
};

int test()
{
    int *df = new int;
    SmartPointer pointer = new int(4);
    SmartPointer pointer2(pointer);
    pointer.info();
    pointer2.info();
    cout << &pointer  << endl; 
    cout << &pointer2 << endl;
    return 0;
}


int main()
{
    test(); 
    cout << "\nhhhhhhhhhhhh\n\n";
    return 0;
}