



template <class T>
bool containing_this(T *arr, int len, T item){
    for (int i = 0; i< len; i++){
        if (arr[i] == item){
            return true;
        };

    }
    return false;
}


