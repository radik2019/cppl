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

    // TOFIX
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
                        current->pnext = current->pnext->pnext;
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
    Node<T> *current = this->head;
    cout << "[";
    while (current->pnext != nullptr)
    {
        cout << current->data << ", ";
        current = current->pnext;
    }
    cout << current->data << "]\n";
}

int main()
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
    cout << lst.pop(0) << "\n\n";
    cout << lst.pop() << "\n\n";
    cout << lst.pop(3) << "\n\n";
    cout << lst.pop() << "\n\n";
    // cout << lst.pop(1) << "\n\n";
    // cout << lst.pop(2) << "\n\n";
    // lst.pop(2);
    lst.print();

    return 0;
}
