#include "../r_header.h"
#include <fstream>
#include <exception>

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
    catch (const exception &e){
        cerr << "Exceptions:     " << e.what() << endl;
    }
    catch ( ...){
        cerr << "Other Exceptions!!!!!:     "  << endl;
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
