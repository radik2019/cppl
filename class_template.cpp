
#include "r_header.h"

// important  ------------------------ CLASS TEMPLATE --------------------------

template <typename T>
class TestClass
{
protected:
    T value;
    string typeValue;
    string v_str = "St6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE";
    string v_int = "St6vectorIiSaIiEE";
    string v_double = "St6vectorIdSaIdEE";
    string integer = "i";
    string dbl = "d";
    string str = "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE";

public:
    TestClass(T value)
    {
        this->value = value;
    }
    void getInfo()
    {
        string s = typeid(this->value).name();

        if (this->v_double == s)
        {
            cout << "\n====== Vector  Double ======\n";
            this->typeValue = "Vector_Double";
        }
        else if (this->v_str == s)
        {
            cout << "\n====== Vector  String ======\n";
            this->typeValue = "Vector_String";
        }
        else if (this->v_int == s)
        {
            cout << "\n====== Vector  Integer ======\n";
            this->typeValue = "Vector_Integer";
        }
        else if (this->str == s)
        {
            cout << "\n======      String    =======\n";
            this->typeValue = "String";
        }
        else if (this->dbl == s)
        {
            cout << "\n======       Double   =======\n";
            this->typeValue = "Double";
        }
        else if (this->integer == s)
        {
            cout << "\n======      Integer   =======\n";
            this->typeValue = "Integer";
        }
        cout << "value:\t" << sizeof(value) << "\n";
        cout << "type: \t" << this->typeValue << "\n";
    }
};

template <>
class TestClass<bool>
{
    /*tipa perezagruzka classa no tolko dlja bool*/
protected:
    bool value;
    string typeValue;

public:
    TestClass(bool value)
    {
        this->value = value;
    }
    void getInfo()
    {
        string s = typeid(this->value).name();
        this->typeValue = "Bool";
        cout << "\n======        BOOL      ======\n";
        cout << "value:\t" << sizeof(value) << "\n";
        cout << "type: \t" << this->typeValue << "\n";
    }
};

class ChildClass : public TestClass<int>
{
public:
    ChildClass(int data) : TestClass(data)
    {
        cout << "ChildClass2 is created\n\n";
    }
};

template <typename T>
class Ch : public TestClass<T>
{
public:
    Ch(T value) : TestClass<T>(value)
    {
        cout << "Ch is created\n\n";
    }
};

void test2()
{
    bool s = 1;
    Ch<int> df(78);
    df.getInfo();
}

void test()
{
    vector<int> vct;
    TestClass<vector<int>> n(vct);
    n.getInfo();
    cout << "\n\n";
    double vct2;
    TestClass<double> n2(vct2);
    n2.getInfo();

    cout << "\n\n";
    string vct3;
    TestClass<string> n3(vct3);
    n3.getInfo();
}

int main()
{

    test2();
    return 0;
}
