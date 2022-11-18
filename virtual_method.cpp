#include "r_header.h"

class VirtMeth
{
private:
public:
    virtual void info()
    {
        cout << "Message from virtual method:  " << endl;
    }

    virtual ~VirtMeth()
    {
    }
};

class Human : public VirtMeth
{
private:
    string msg = " oooooooooooooo ";

public:
    void info() override
    {
        cout << this->msg << endl;
        ::VirtMeth::info();
    }
    Human(/* args */);
    ~Human() override;
};

Human::Human(/* args */)
{
}

Human::~Human()
{
}

int main()
{
    Human hm;
    hm.info();
    return 0;
}
