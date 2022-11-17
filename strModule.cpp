#include <vector>
#include "r_header.h"

class StringR
{
private:
    string s;
    int len;

public:
    StringR(string s);
    ~StringR();

    static int check_floating_point(string s)
    {
        /*Check  and return integer count of floating points*/
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
            {
                ++count;
            }
        }
        return count;
    }

    static bool is_int(string s)
    {
        string symbols = "0123456789";
        bool flag;
        for (int i = 0; i < s.length(); i++)
        {
            flag = false;
            for (int k = 0; k < symbols.length(); k++)
            {
                if (s[i] == symbols[k])
                    flag = true;
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }

    static int to_int(string s)
    {
        if (is_int(s))
        {
            int num = 0;
            map<char, int> dict_int = number_dict();
            for (int i = 0; i < s.length(); i++)
            {
                num += (dict_int[s[i]] * pow(10, (s.length() - i - 1)));
            }
            return num;
        }
        return 0;
    }

    static bool is_double(string s)
    {
        string symbols = "0123456789.";
        if (check_floating_point(s) != 1)
        {
            return false;
        }
        bool flag;
        for (int i = 0; i < s.length(); i++)
        {
            flag = false;
            for (int k = 0; k < symbols.length(); k++)
            {
                if (s[i] == symbols[k])
                    flag = true;
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }

    static double to_doublee(string s)
    {
        if (is_double(s))
        {
            string integer = "";
            string defis = "";
            int count = s.find(".");
            for (int i = count + 1; i < s.length(); i++)
            {
                defis += s[i];
            }
            for (int k = 0; k < count; k++)
            {
                integer += s[k];
            }
            double x;
            double y;
            x = to_int(integer) / 1;
            y = to_int(defis) / (pow(10, defis.length()));
            double f = x + y;
            return f;
        }
        else
        {
            throw "Division by zero condition!";
        }
    }

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
                lst.push_back(to_int(temp));
                temp = "";
            }
        }
        if (temp != "")
        {
            lst.push_back(to_int(temp));
        }
        return lst;
    }

};

StringR::StringR(string s)
{
    this->s = s;
    this->len = s.length();
}
StringR::~StringR()
{
}

void test(){
    StringR mystring("23.4");
    cout << "\n\StringR mystring(\"23.4\")\n";
    cout <<  "StringR::check_floating_point(\"234234.234534\") =   " <<StringR::check_floating_point("234234.234534") << endl;



}

int main()
{
    test();
    return 0;
}
