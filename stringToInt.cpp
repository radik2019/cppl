#include <map>
#include <string>
#include <cmath>
using namespace std;

map<char, int> number_dict();
bool is_int(string s);
int to_int(string s);
bool is_double(string s);
double to_doublee(string num);

int check_floating_point(string num);

int check_floating_point(string num)
{
    int count = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '.')
        {
            ++count;
        }
    }
    return count;
}

bool is_int(string s)
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

int to_int(string s)
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

bool is_double(string s)
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

double to_doublee(const string num)
{
    if (is_double(num))
    {
        string integer = "";
        string defis = "";
        int count = num.find(".");
        for (int i = count + 1; i < num.length(); i++)
        {
            defis += num[i];
        }
        for (int k = 0; k < count; k++)
        {
            integer += num[k];
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


map<char, int> number_dict()
{
    string symbols = "0123456789.";
    map<char, int> dict_num;
    for (int i = 0; i < symbols.length(); i++)
    {
        dict_num.insert(pair<char, int>(symbols[i], i));
    }
    return dict_num;
}