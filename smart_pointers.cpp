#include "r_header.h"

template <typename T>
class SmartPointer
{
private:
    T *ptr;

public:
    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
        cout<< *this->ptr << "   Constructor\n\n";
    }
    ~SmartPointer()
    {
        delete this->ptr;
        cout << "Destructor\n\n";
    }
    T& operator*(){
        return *ptr;
    }
};

int test()
{
    SmartPointer<int> pointer = new int(4);
    cout << *pointer << endl; 
    return 0;
}


int main()
{
    test(); 
    cout << "hhhhhhhhhhhh";
    return 0;
}