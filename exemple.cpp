#include <iostream>
#include <string>


void print(int lst[], const int len);
void bubleSort(int lst[], const int len);
void stringFunc();



int main(){
    // int h;
    // int lst[] = {67,2,10, 99,6, 74, 4,12,3, 8, 72, 18 ,23, 43,7, 32, 1,89, 5,40,9};
    // const int len = sizeof(lst) / sizeof(lst[0]);
    // bubleSort(lst, len);
    // print(lst, len);
    stringFunc();
    return 0;
}


void stringFunc(){
    std::string name;
    std::getline(std::cin, name);
    std::cout << name;
}


void bubleSort(int lst[], const int len){
    for(int i = 0; i< len; ++i){
        
        int les = lst[i];
        for(int k = i; k < len; ++k){
            // std::cout << k << std::endl;
            if (lst[k] < lst[i]){
                int temp= lst[k];
                lst[k] = lst[i];
                lst[i] = temp;
            }
        }
    }
}


void print(int lst[], const int len){
    for(int i = 0; i< len; ++i){

        std::cout << lst[i]<< " ";
    }
}