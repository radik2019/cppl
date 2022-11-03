#include <map>
#include <string>
#include <cmath>
using namespace std;



map<char, int> number_dict();

bool is_int(string s){
    string symbols = "0123456789";
    bool flag;
    for (int i = 0; i < s.length(); i++){
        flag = false;
        for (int k = 0; k < symbols.length(); k++){
            if (s[i] == symbols[k]) flag = true;
        }
        if(!flag){
            return false;
        }  
    }
    return true;
    
}

int to_int(string s){
    if (is_int(s)){
        int num = 0;
        map<char, int> dict_int = number_dict();
        for (int i = 0; i < s.length(); i++){
            num += (dict_int[s[i]] * pow(10, (s.length()-i - 1)));
        }
        return num;
    }
    return 0;
}


bool is_double(string s){
    string symbols = "0123456789.";
    bool flag;
    for (int i = 0; i < s.length(); i++){
        flag = false;
        for (int k = 0; k < symbols.length(); k++){
            if (s[i] == symbols[k]) flag = true;
        }
        if(!flag){
            return false;
        } 
    }
    return true;
}


map<char, int> number_dict(){
    map<char, int> dict_num;
    dict_num.insert(pair<char, int>('0', 0));
    dict_num.insert(pair<char, int>('1', 1));
    dict_num.insert(pair<char, int>('2', 2));
    dict_num.insert(pair<char, int>('3', 3));
    dict_num.insert(pair<char, int>('4', 4));
    dict_num.insert(pair<char, int>('5', 5));
    dict_num.insert(pair<char, int>('6', 6));
    dict_num.insert(pair<char, int>('7', 7));
    dict_num.insert(pair<char, int>('8', 8));
    dict_num.insert(pair<char, int>('9', 9));
    return dict_num;
}

