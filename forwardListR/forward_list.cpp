#include "../r_header.h"

template <typename T>
class List
{
private:
    template <typename T1>
    class Node
    {
    public:
        Node *pnext;
        T1 data;
        Node(T1 data = T1(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pnext = pNext;
        }
        ~Node()
        {
            cout << "delete Node: " << this->data << "\n";
        }
    };
    int Size;

public:
    List();
    Node<T> *head;

    void pushBack(T data)
    {
        if (head == nullptr)
        {
            this->head = new Node<T>(data);
        }
        else
        {
            Node<T> *current = this->head;
            while (current->pnext != nullptr)
            {
                current = current->pnext;
            }
            current->pnext = new Node<T>(data);
        }
        ++this->Size;
    }

    int getSize()
    {
        return this->Size;
    }






    List *operator+(const List &obj){
        List<T> *temp = new List<T>;
        Node<T> *current = this->head;
        Node<T> *temp_obj = obj.head;
        while (current->pnext != nullptr)
        {
            temp->pushBack(current->data);
            current = current->pnext;
        }
        temp->pushBack(current->data);

        while (temp_obj->pnext != nullptr)
        {
            temp->pushBack(temp_obj->data);
            temp_obj = temp_obj->pnext;
        }
        temp->pushBack(temp_obj->data);
        return temp;
    }








    T &operator[](const int index)
    {
        int counter = 0;
        Node<T> *current = this->head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pnext;
            ++counter;
        }
        return current->data;
    }

    void print();

    void insert(const int index, T data)
    {
        if (index == 0)
        {
            Node<T> *temp = new Node(data, this->head);
            this->head = temp;
            return;
        }
        else
        {
            if (index > this->Size)
            {
                throw "Index out of range!\n";
            }
            int count = 1; // perche` il primo (0) e` head
            Node<T> *object = this->head;
            while (true)
            {
                if (count == index)
                {
                    Node<T> *temp = new Node(data, object->pnext);
                    object->pnext = temp;
                    ++this->Size;
                    return;
                }
                ++count;
                object = object->pnext;
            }
        }
    }

    void clear()
    {
        while (this->Size)
        {

            Node<T> *temp = this->head;
            this->head = this->head->pnext;
            delete temp;
            --this->Size;
        }
    }

    int pop_front()
    {

        int n = this->head->data;
        Node<T> *temp = this->head;
        this->head = this->head->pnext;
        delete temp;
        --this->Size;

        return n;
    }

    int pop()
    {
        int index = this->Size - 1;

        Node<T> *current = this->head;
        int n;
        int count = 0;
        while (current->pnext != nullptr)
        {
            if (current->pnext->pnext == nullptr)
            {
                n = current->pnext->data;
                current->pnext = nullptr;
                --this->Size;
                return n;
            }
            current = current->pnext;
            ++count;
        }
        return n;
    }

    int pop(int index)
    {
        if (index >= this->Size)
        {
            throw("Index out of range\n\n");
        }
        else
        {
            Node<T> *current = this->head;
            int n;
            int count = 0;
            if (index == 0)
            {
                n = this->head->data;
                this->head = this->head->pnext;
                return n;
            }
            else
            {
                while (current->pnext != nullptr)
                {
                    if (count == (index - 1))
                    {
                        n = current->pnext->data;
                        Node<T> *temp = current->pnext;         // si crea il puntatore del nodo da cui ci sganciamo
                        current->pnext = current->pnext->pnext; // si campbia il puntatore del prossimo nodo
                        delete temp;                            // si cancella il nodo rimasto senza collegamento
                        --this->Size;
                        return n;
                    }
                    current = current->pnext;
                    ++count;
                }
                return n;
            }
        }
    }

    bool is_empty()
    {
        return (this->head == nullptr);
    }
};

template <typename T>
List<T>::List()
{
    this->Size = 0;
    this->head = nullptr;
}

template <class T>
void List<T>::print()
{
    if (!this->Size)
    {
        cout << "[]\n";
        return;
    }
    Node<T> *current = this->head;
    cout << "[";
    while (current->pnext != nullptr)
    {
        cout << current->data << ", ";
        current = current->pnext;
    }
    cout << current->data << "]\n";
}

void test()
{
    List<int> lst;
    lst.pushBack(5);
    lst.pushBack(6);
    lst.pushBack(5);
    lst.pushBack(8);
    lst.pushBack(24);
    lst.pushBack(54);
    lst.pushBack(15);
    lst.pushBack(87);
    lst.pushBack(92);
    lst.pushBack(619);
    lst.pushBack(1946);
    cout << lst.getSize() << endl;
    lst.print();
    // cout << lst.pop(0) << "\n\n";
    // cout << lst.pop() << "\n\n";
    // cout << lst.pop(3) << "\n\n";
    // cout << lst.pop() << "\n\n";
    // cout << lst.pop(1) << "\n\n";
    cout << "  **** " << lst.pop_front() << "\n";
    cout << "  **** " << lst.pop_front() << "\n";
    cout << "  **** " << lst.pop_front() << "\n";
    lst.print();
    lst.clear();
    // lst.pop(2);
    lst.print();
}

void test_clear()
{
    List<int> lst;
    lst.clear();
    lst.pushBack(619);
    lst.clear();
}

void test_insert()
{
    List<int> lst;
    lst.pushBack(5);
    lst.pushBack(6);
    lst.pushBack(5);
    lst.pushBack(8);
    lst.pushBack(24);
    lst.pushBack(54);
    lst.pushBack(15);
    lst.pushBack(87);
    lst.pushBack(92);
    lst.pushBack(61);
    lst.print();
    for (int i = 0; i < 12; i++)
    {
        cout << "\n\n===================== " << i << " ===================\n";
        try
        {
            lst.insert(i, 4444);
            lst.print();
            lst.pop(i);
            lst.print();
        }
        catch (const char *e)
        {
            std::cerr << e << '\n';
        }
    }
}

void test_is_empty()
{
    List<int> lst;
    cout << "is empty?  " << lst.is_empty() << endl;
    lst.pushBack(619);
    cout << "is empty?  " << lst.is_empty() << endl;
}

void test_operator_plus(){
    List<int> lst;
    List<int> lst2;
    lst.pushBack(4);
    lst.pushBack(4);
    lst.pushBack(4);
    lst.pushBack(10);
    lst2.pushBack(1);
    lst2.pushBack(1);
    lst2.pushBack(1);
    lst2.pushBack(2);
    List<int> *lst3 = lst+lst2;
    lst3->print();
}

int main()
{
    test_operator_plus();

    return 0;
}
