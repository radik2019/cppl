
#include "../r_header.h"

class SmartPointer
{
private:
    int *ptr;

public:
    static inline int count = 0;
    SmartPointer(int *ptr)
    {
        this->ptr = ptr;
        ++this->count;
        cout << this->count << "   Constructor\n\n";
    }
    ~SmartPointer()
    {
        if (this->count == 1)
        {
            delete this->ptr;
            cout << "Destructor\n\n";
        }
        else
        {
            --this->count;
            cout << "Meno 1, count = " << this->count << endl;
        }
    }
    int &operator*()
    {
        return *ptr;
    }

    void info()
    {
        cout << "\n\n===================================\n";
        cout << "data:\t" << this->count << endl;
        cout << "data arr:\t" << this->ptr[0] << endl;
        cout << "===================================\n\n";
    }
};

void test()
{
    int *nm = new int[2];
    SmartPointer df(nm);
    df.info();
    SmartPointer df2(nm);
    df2.info();
}

int main()
{
    test();

    return 0;
}
