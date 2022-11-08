

template <typename T>
void print(T *arr, int length){
    cout << "[";
    for (int i = 0; i < (length - 1); i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1] << "]\n";
}

void print(){
    cout << '\n' << endl;
}

template <class T>
void print(T a){
    cout << a << endl;
}

template <class T, class T2>
void print(T a, T2 b){
    cout << a << ' ' << b << endl;
}

template <class T, class T2, class T3>
void print(T a, T2 b, T3 c){
    cout << a << ' ' << b << ' ' << c << endl;
}

template <class T, class T2, class T3, class T4>
void print(T a, T2 b, T3 c, T4 d){
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}


/*print 2d dyanamic array*/
template <class T>
void print(T *&arr, int &col, int &row)
{
    string final_char = "], ";
    cout << "[";
    for (int k = 0; k < col; k++){
        if (k == row - 1){
            final_char = "]";
        }
        else{
            final_char = "], ";
        }
        cout << "[";
        for (int i = 0; i < row; i++){
            if (i == row - 1){
                final_char = "], ";
                cout << arr[k][i];
            } else {
                cout << arr[k][i] << ", ";
            }

            if ((i == row - 1) && (k == col - 1)){
                final_char = "]";
            }
        }
        cout << final_char;
    }
    cout << "]\n";
}



