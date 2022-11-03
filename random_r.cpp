

void randGenIntArr(
    int start,
    int stop,
    int length,
    int* lst){
    /*list of random integer in range of "start" to stop*/
    srand(time(NULL));
    int num = rand() % (stop - start) + start;
    for (int i = 0; i < length; i++)
    {
        lst[i] = num;
        num = rand() % (stop - start) + start;
    }
}


template <typename T>
void shuffleInt(int len, T* lst)
{
    int indx[len];
    int temp;
    randGenIntArr(0, len, len, indx);
    for (int i = 0; i < len; i++)
    {
        temp = lst[i];
        lst[i] = lst[indx[i]];
        lst[indx[i]] = temp;
    }
}

