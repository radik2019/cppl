// Начнем с директив препроцессора. R_HEADER – это произвольное уникальное имя
//(обычно используется имя заголовочного файла)
#ifndef R_HEADER
#define R_HEADER
// #define PRINT_JOE "Alex"
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
#include <vector>
using namespace std;

#include "print_r.cpp"
#include "utils.cpp"
#include "random_r.cpp"
#include "dynamicArray.cpp"
#include "stringToInt.cpp"

// А это уже содержимое заголовочного файла
//int add(int x, int y); // прототип функции add() (не забывайте точку с запятой конце!)

// Заканчиваем директивой препроцессора
#endif


// ECOPELLE

