#include <memory>
#include "../r_header.h"
/*
    smart_pointers
    autoptr         // deprecated!
    unique_ptr
    shared_ptr
*/

class Owner
{
public:
    shared_ptr<int> owningPtr;

    Owner()
    {
        owningPtr = make_shared<int>();
    }
};

class User
{
    weak_ptr<int> usingPtr;

public:
    User(std::weak_ptr<int> object)
    {
        usingPtr = object;
    }

    void use()
    {
        if (shared_ptr<int> object = usingPtr.lock())
        { //Попытка получить оригинальный std::shared_ptr из std::weak_ptr,
          // если возвращён пустой std::shared_ptr, значит, объект уже был удалён
            // object->func();
            cout << "Counter:  " << object.use_count() << endl;
        }
        else
        {
            cout << "object is deleted!\n";
            //Объект уже удалён
        }
    }
};

void test_weak_ptr()
{
    Owner owner;
    User user(owner.owningPtr);
    user.use();
}

template <typename T>
class SmartPointer
{
private:
    T *ptr;

public:
    static inline int count = 0;
    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
        ++this->count;
        cout << this->count << "   Constructor\n";
    }
    ~SmartPointer()
    {
        if (this->count == 1)
        {
            delete this->ptr;
            cout << "Destructor\n";
        }
        else
        {
            --this->count;
            cout << "Meno 1, count = " << this->count << endl;
        }
    }
    int &operator*()
    {
        return *ptr;
    }

    void info()
    {
        cout << "\n===================================\n";
        cout << "count:\t" << this->count << endl;
        cout << "data arr:\t" << this->ptr[0] << endl;
        cout << "===================================\n\n";
    }
};

template <typename T2>
class SmartPointer2
{
private:
    T2 *ptr;

public:
    static inline int count = 0;
    SmartPointer2(T2 *ptr)
    {
        this->ptr = ptr;
        ++this->count;
        cout << this->count << "   Constructor\n";
    }
    ~SmartPointer2()
    {
        delete this->ptr;
    }
    int &operator*()
    {
        return *ptr;
    }

    void info()
    {
        cout << "\n===================================\n";
        cout << "count:\t" << this->count << endl;
        cout << "data arr:\t" << this->ptr[0] << endl;
        cout << "===================================\n\n";
    }
};

void test()
{
    int *nm = new int[2]{23, 56};
    //----------------------------------------
    SmartPointer df(nm);
    df.info();
    //----------------------------------------
    SmartPointer df2(nm);
    df2.info();
    //----------------------------------------
    SmartPointer df3(nm);
    df3.info();
    //----------------------------------------
    SmartPointer df4(nm);
    df4.info();
}

void test_unique_ptr()
{
    // std::unique_ptr<int> ptr2;
    std::unique_ptr<int> ptr(new int(8)); //Объект класса X создан в динамической памяти
    //Здесь указатель ptr покидает свою область видимости и уничтожается,
    // но перед этим удаляет из памяти объект, на который указывает

    /*
    se volessi creare un puntatore :
    int* newPtr = ptr;
    mi darebbe errore in quanto si puo` avere un solo puntatore sul dato
    dichiarato 'unique_ptr'
    Anche se si lancera` un'eccezione, unique_ptr garantisce la chiamata
    del destructor dell dato
    */

    unique_ptr<int> vrt = make_unique<int>(345); // senza utilizzare 'new'
    auto ptr2 = std::make_unique<int>(7);        // senza utilizzare 'new'
    int *df;
    // move( ptr2, df);
    ptr2.swap(ptr);

    cout << *ptr2 << endl
         << endl;
}

void test_shared_ptr()
{
    /*
    A  -> B
    C  -> B
    quando 2 puntatori puntano sullo stesso indirizzo
    */
    std::shared_ptr<int> ptr = std::make_shared<int>(); //Создаётся объект
    {
        std::shared_ptr<int> ptr2 = ptr; //Теперь у объекта два владельца, выраженных в виде ptr и ptr2
        cout << "count  " << ptr.use_count() << endl;
    }
    cout << "count  " << ptr.use_count() << endl; // ptr2 выходит из области видимости, но объект не освобождается, потому что есть ptr, который по-прежнему ссылается на него
} // ptr выходит из области видимости, и объект уничтожается

int main()
{
    test_weak_ptr();
    // uint64_t number2;
    // // short number;
    // unsigned short int number = 65535;
    // cout << sizeof(number) << ' ' << number << endl;

    return 0;
}
