

#include <iostream>
#include <ctime>
#include <string>
using namespace std;
#include "r_header.h"



int main()
{
    int cols = 12;
    int rows = 12;
    int **arr = new int *[rows];
    int *arr2 = new int[cols];

    for (int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            arr[i][k] = rand() % 100;
        }
    }
    print();
    pushBack1(arr, arr2, cols, rows);
    print(arr, rows, cols);
    print();
    return 0;
}
