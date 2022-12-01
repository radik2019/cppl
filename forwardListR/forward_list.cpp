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
        }
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
    return 0;
}
