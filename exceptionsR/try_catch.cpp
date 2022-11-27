#include "../r_header.h"
#include <fstream>
#include <exception>

class ExceptionR : public exception
{
private:
    string _msg;
    int dataState;

public:
    ExceptionR(const string &msg, int dataState) : _msg(msg)
    {
        this->dataState = dataState;
        cout << "Exceptionr:" << endl;
    }

    virtual const char *what() const noexcept override
    {
        return _msg.c_str();
    }
    
    int getDataState()
    {
        return this->dataState;
    }
};

int division(int x, int y)
{
    if (x > y)
    {
        throw ExceptionR("Error:   x > y\n\n", 2);
    }
    else if ((x == 0) && (y == 0))
    {
        throw ExceptionR("\n  Error:   x = 0;  y = 0\n\n", 34);
    }
    return x * y;
}

void test3()
{
    try
    {
        cout << "\n\n" << division(0, 0) << "\n\n";
    }
    catch (const ExceptionR &er)
    {
        std::cerr << er.what() << '\n';
        
        // cout << e.getDataState() << "\n\n";
    }
}

void year_of_birth(int num)
{
    if (num > 2020)
    {
        throw 2;
    }
    else if ((num > 0) && (num < 1900))
    {
        throw "troppo piccolo il numero";
    }
    if (num < 0)
    {
        exception e;
        throw e;
    }

    cout << "Il tuo anno di nascita e` " << num;
}

void test2()
{
    try
    {
        year_of_birth(-344);
    }
    catch (const int e)

    {
        cout << "    " << (e == 1) << endl;
        std::cerr << "\n\n"
                  << e << '\n';
    }
    catch (const char *e)
    {
        cout << "    " << (e == "troppo piccolo il numero") << endl;
        std::cerr << "\n\n"
                  << e << '\n';
    }
    catch (const exception &e)
    {
        cerr << "Exceptions:     " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Other Exceptions!!!!!:     " << endl;
    }
}

void test()
{
    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        string s;
        fin.open("___file.txt");
        fin >> s;
        cout << s << "stai nell blocco try\n";
    }
    catch (const ifstream::failure &e)
    {
        cout << "\n\nstai nell blocco exception\n\n";
        std::cerr << e.what() << '\n';
        std::cerr << e.code() << '\n';
        cout << "\n\nstai nell blocco exception\n\n";
    }
}
