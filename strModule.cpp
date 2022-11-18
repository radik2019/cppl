#include <vector>
#include "r_header.h"

class NumberManager
{
private:
    string numberString;
    int len;
    map<char, int> dict_num;
    string symbols = "0123456789.";

public:
    NumberManager(string numberString);
    ~NumberManager();

    int check_floating_point()
    {
        int count = 0;
        for (int i = 0; i < this->numberString.length(); i++)
        {
            if (this->numberString[i] == '.')
            {
                ++count;
            }
        }
        return count;
    }

    bool is_int()
    {
        string symbols = "0123456789";
        bool flag;
        for (int i = 0; i < this->len; i++)
        {
            flag = false;
            for (int k = 0; k < symbols.length(); k++)
            {
                if (this->numberString[i] == symbols[k])
                    flag = true;
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }

    int to_int()
    {
        if (this->is_int())
        {
            int num = 0;
            map<char, int> dict_int = number_dict();
            for (int i = 0; i < this->numberString.length(); i++)
            {
                num += (dict_int[this->numberString[i]] * pow(10, (this->numberString.length() - i - 1)));
            }
            return num;
        }
        return 0;
    }

    bool is_double()
    {
        string symbols = "0123456789.";
        if (this->check_floating_point() != 1)
        {
            return false;
        }
        bool flag;
        for (int i = 0; i < this->len; i++)
        {
            flag = false;
            for (int k = 0; k < symbols.length(); k++)
            {
                if (this->numberString[i] == symbols[k])
                    flag = true;
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }

    double to_doublee()
    {
        if (this->is_double())
        {
            string integer = "";
            string defis = "";
            int count = this->numberString.find(".");
            for (int i = count + 1; i < this->numberString.length(); i++)
            {
                defis += this->numberString[i];
            }
            for (int k = 0; k < count; k++)
            {
                integer += this->numberString[k];
            }
            double x;
            double y;
            x = NumberManager(integer).to_int();
            y = NumberManager(defis).to_int() / (pow(10, defis.length()));
            double f = x + y;
            return f;
        }
        else
        {
            throw "Division by zero condition!";
        }
    }
};

NumberManager::NumberManager(string numberString)
{
    this->numberString = numberString;
    this->len = this->numberString.length();

    for (int i = 0; i < this->symbols.length(); i++)
    {
        this->dict_num.insert(pair<char, int>(this->symbols[i], i));
    }
}

NumberManager::~NumberManager()
{
}

class StringR
{
private:
    string s;
    int len;

    static bool isDigit(char symbol)
    {
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

public:
    StringR(string s);
    StringR();
    ~StringR();

    char operator[](int index)
    {
        return this->s[index];
    }

    void operator=(string new_string)
    {
        this->s = new_string;
    }

    string operator*(int n)
    {
        string temp;
        for (int i = 0; i < n; i++)
        {
            temp += this->s;
        }
        return temp;
    }

    string getS()
    {
        return this->s;
    }

    vector<int> extractDigits()
    {
        /*Extract digits from string and return a vector of integers*/
        vector<int> lst;
        string temp = "";
        for (int i = 0; i < this->s.length(); i++)
        {
            if (isDigit(this->s[i]))
            {
                temp += this->s[i];
            }
            else if (temp != "")
            {
                lst.push_back(NumberManager(temp).to_int());
                temp = "";
            }
        }
        if (temp != "")
        {
            lst.push_back(NumberManager(temp).to_int());
        }
        return lst;
    }
};

StringR::StringR()
{
    this->s = "";
    this->len = 0;
}

StringR::StringR(string s)
{
    this->s = s;
    this->len = s.length();
}

StringR::~StringR()
{
}

void test()
{

    StringR sd;
    sd = "1234";

    string temp = sd * 10;
    print(sd[1]);
}

int main()
{
    test();
    cerr << "hello";

    // cout << to_string(2.34)+"dfg" << endl;
    return 0;
}
