
#include <iostream>
#include <string>
#include <cstdarg>
using namespace std;

// Эллипсис должен быть последним параметром.
// Переменная count - это количество переданных аргументов
double findAverage(int count, ...)
{
    double sum = 0;

    // Мы получаем доступ к эллипсису через va_list, поэтому объявляем
    // переменную этого типа

    va_list list;
    
    // Инициализируем va_list, используя va_start. Первый параметр – это
    // список, который нужно инициализировать.

    // Второй параметр - это последний параметр, который не является эллипсисом

    va_start(list, count);
    // Перебираем каждый из аргументов эллипсиса
    // Используем va_arg для получения параметров из эллипсиса.
    // Первый параметр - это va_list, который мы используем.
    // Второй параметр - это ожидаемый тип параметров
    sum += va_arg(list, int);
    // Выполняем очистку va_list, когда уже сделали всё необходимое
    cout << va_arg(list, int) << endl << endl;
    cout << va_arg(list, int) << endl << endl;
    cout << va_arg(list, int) << endl << endl;
    va_end(list);
    

    return sum / count;
}

int main()
{

    std::cout << findAverage(4, 1, 2, 3, 4) << '\n';

    std::cout << findAverage(5, 4,5,6,7,8) << '\n';
}
