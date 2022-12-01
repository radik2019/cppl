#include "../r_header.h"

template <typename T>
class List
{
private:
    template <typename T1>
    class Node
    {
    private:
        /* data */
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
        }
    };

public:
    Node<T> *head;
    int Size;

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

    void print(){
        // TODO 
    }

    List(/* args */);
    ~List();
};
template <typename T>
List<T>::List(/* args */)
{
    Size = 0;
    head = nullptr;
}
template <typename T>
List<T>::~List()
{
}

int main()
{
    List<int> lst;
    lst.pushBack(5);
    lst.pushBack(6);
    lst.pushBack(87);
    lst.pushBack(12);
    lst.pushBack(619);
    lst.pushBack(91);
    lst.print();
    cout << "[";
    for (int i = 0; i < lst.getSize() - 1; i++)
    {
        cout << lst[i] << ", ";
    }
    
    cout << lst[lst.getSize()-1]<< "]\n";   
    
    return 0;
}
