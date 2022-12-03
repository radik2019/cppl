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
    };
    int Size;
public:
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

    List(/* args */);
};

template <typename T>
List<T>::List()
{
    this->Size = 0;
    this->head = nullptr;
}

template<class T> void List<T>::print(){
    Node<T> *current = this->head;
    cout << "[";
    while (current->pnext !=nullptr)
    {
        cout << current->data << ", ";
        current = current->pnext;
    }
    cout << current->data<< "]\n";
}

int main()
{
    List<int> lst;
    lst.pushBack(5);
    lst.pushBack(6);
    lst.pushBack(87);
    lst.print();
    lst.pushBack(12);
    lst.pushBack(619);
    lst.pushBack(91);
    lst.print(); 
    
    return 0;
}
