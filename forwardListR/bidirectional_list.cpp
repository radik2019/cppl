#include "../r_header.h"

template <typename T>
class BDList
{
private:
    template <typename T1>
    class Node
    {

    public:
        Node<T1> *pnext;
        Node<T1> *previos;
        T data;
        Node(T1 data = T1(), Node *previos = nullptr, Node *pnext = nullptr)
        {
            this->previos = previos;
            this->pnext = pnext;
            this->data = data;
        }
        ~Node();
    };
    int Size;

public:
    Node<T> *head;
    Node<T> *tail;
    BDList()
    {
        this->Size = 0;
        this->head = nullptr;
        this->tail = nullptr;
        ++this->Size;
    }
    ~BDList()
    {
        cout << "deleted\n";
    }

    void print()
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
            cout  << current->data << ", ";
            current = current->pnext;
        }
        cout << current->data << "]\n";
    }




    void printReverse()
    {
        if (!this->Size)
        {
            cout << "[]\n";
            return;
        }
        Node<T> *current = this->tail;
        cout << "[";
        while (current->previos != nullptr)
        {
            cout  << current->data << ", ";
            current = current->previos;
        }
        cout << current->data << "]\n";
    }


    void pushBack(T data){
         
        if (head == nullptr)
        {
            this->head = new Node<T>(data);
        }
        else
        {
            Node<T> *currH = this->head;
            /*Creando il puntatore dell`oggetto Node head*/

            while (currH->pnext != nullptr)
            {
                currH = currH->pnext;
            }
            currH->pnext = new Node<T>(data, currH);
            currH = currH->pnext;
            this->tail = currH; // Imposto la coda ogetto presente
            /*Si crea un nuovo Node e li si da come parametri il dato 
            e il puntatore del Node presente*/
        }
        ++this->Size;
    }

    void pushFront(T data){
         
        if (this->head == nullptr)
        {
            this->head = new Node<T>(data);
        }
        else
        {
            Node<T> *temp = new Node<T>(data, nullptr ,this->head);
            this->head->previos = temp;
            this->head = temp;
        }
        ++this->Size;
    }
};

void test_init()
{

    BDList<int> lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(4);
    lst.pushBack(5);
    lst.pushBack(6);
    lst.pushFront(11);
    lst.pushFront(12);
    lst.pushFront(13);
    lst.pushFront(14);

    lst.print();
    cout << "\n\n";
    lst.printReverse();
}

int main()
{

    test_init();
    return 0;
}
