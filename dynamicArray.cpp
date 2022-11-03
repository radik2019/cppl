




void dynamicDoc(){
  string s = "\
  void pushBack(int *&arr, int &size, const int value)\n\
  \t\t- add value to the end of array\n\n\
  int pop(int *&arr, int &size)\n\
  \t\t- remove last value and return it\n\n\
  int pop(int *&arr, int &size, const int index)\n\
  \t\t- remove from array value with index 'index' and return it\n\n\
  bool exists(int *&arr, int &size, const int value)\n\
  \t\t check if value exixts in array and return bool\n\n\
  void remove(int *&arr, int &size, const int index)\n\
  \t\t- remove only the first value found which is equal to the requested value\n\n\
  void insert(int *&arr, int &size, const int value, const int index)\n\
  \t\t- insert value to the index in array\n\n\
  insert(int *&arr, int &size, const int value, const int index)\n\
  \t\t- slice array from start to stop(array[stop] not included)\n";
  print(s);
}

template <class T>
void copyArray(T *&arr, T *&arr2, int &size){
  for (int i = 0; i < size; i++){
    arr2[i] = arr[i];
  }
}

template <class T>
void slice(T *&arr, int &size, const int start, const int stop){
  if ((stop - start) < 1){
    return;
  }
  int length = stop - start;
  T *newArray = new T[length];
  int new_index = 0;
  for (int i = start; i < stop; i++){
    newArray[new_index] = arr[i];
    new_index++;
  }
  delete[] arr;
  arr = newArray;
  size = length;
}

template <class T>
void insert(T *&arr, int &size, const T value, const int index){
  if (index >= size){
    return;
  }
  T *newArray = new T[size + 1];
  int new_index = 0;
  for (int i = 0; i < size; i++){
    if (i == index){
      newArray[new_index] = value;
      new_index++;
    }
    newArray[new_index] = arr[i];
    new_index++;
  }
  delete[] arr;
  arr = newArray;
  size++;
}


///////////////////////////////////////////////////////////////////
template <class T>
void pushBack(T *&arr, int &size, const T value){
  T *newArray = new T[size + 1];
  for (int i = 0; i < size; i++){
    newArray[i] = arr[i];
  }
  newArray[size] = value;
  delete[] arr;
  arr = newArray;
  size++;
}


void pushBack1(int **&d_arr, int *&arr, int &cols, int &rows){
    int **newArr = new int *[rows + 1];
    newArr[rows] = arr;
    for (int i = 0; i < rows; i++){
        newArr[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; i++){
        newArr[i] = d_arr[i];
        for (int k = 0; k < cols; k++){
            newArr[i][k] = d_arr[i][k];
        }        
    }
    rows++;
    delete[] d_arr;
    d_arr = newArr;
}

///////////////////////////////////////////////////////////////////

int pop(int *&arr, int &size){
  int *newArray = new int[size - 1];
  size--;
  int num = arr[size - 1];
  for (int i = 0; i < size; i++){
    newArray[i] = arr[i];
  }
  delete[] arr;
  arr = newArray;
  return num;
}

int pop(int *&arr, int &size, const int index){
  int *newArray = new int[size - 1];
  int index_new_array = 0;
  for (int i = 0; i < size; i++){
    if (i != index){
      newArray[index_new_array] = arr[i];
      index_new_array++;
    }
  }
  int num = arr[index];
  size--;
  delete[] arr;
  arr = newArray;
  return num;
}

bool exists(int *&arr, int &size, const int value)
{
  for (int i = 0; i < size; i++){
    if (value == arr[i]){
      return true;
    }
  }
  return false;
}

void remove(int *&arr, int &size, const int index){
  if (!exists(arr, size, index)){
    return;
  }
  int *newArray = new int[size - 1];
  int index_new_array = 0;
  bool flag = false;
  for (int i = 0; i < size; i++){
    if (arr[i] != index){
      newArray[index_new_array] = arr[i];
      index_new_array++;
    }
    else{
      if (flag == false){
        flag = true;
      }
      else{
        newArray[index_new_array] = arr[i];
        index_new_array++;
      }
    }
  }

  size--;
  delete[] arr;
  arr = newArray;
}
