#include "../r_header.h"

class BinaryTree
{
private:
    class Node
    {
    public:
        Node *left;
        Node *right;
        int data;

        Node(int data, Node *left = nullptr, Node *right = nullptr)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };

    void _print(Node *current = nullptr)
    {
        if (current == nullptr)
        {
            current = this->head;
        }

        if ((current->left == nullptr) && (current->right == nullptr))
        {
            cout << current->data << ", ";
            return;
        }

        else if ((current->left != nullptr) && (current->right == nullptr))
        {
            cout << current->data << ", ";
            this->_print(current->left);
        }
        else if ((current->left == nullptr) && (current->right != nullptr))
        {
            this->_print(current->right);
            cout << current->data << ", ";
        }
        else
        {
            this->_print(current->right);
            cout << current->data << ", ";
            this->_print(current->left);
        }
    }

public:
    Node *head;

    BinaryTree()
    {
        this->head = nullptr;
    }

    void push(int data)
    {
        if (this->head == nullptr)
        {
            this->head = new Node(data);
        }
        else
        {
            Node *current = this->head;
            while (true)
            {
                if (data <= current->data)
                {
                    if (current->right == nullptr)
                    {
                        current->right = new Node(data);
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
                else
                {
                    if (current->left == nullptr)
                    {
                        current->left = new Node(data);
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
            }
        }
    }

    int getMin()
    {
        Node *current = this->head;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current->data;
    }

    int getMax()
    {
        Node *current = this->head;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current->data;
    }

    bool isEmpty()
    {

        if (this->head == nullptr)
        {
            return true;
        }
        return false;
    }

    bool exists(int data, Node *current = nullptr)
    {

        if (current == nullptr)
        {
            current = this->head;
        }
        if ((current->left == nullptr) && (current->right == nullptr))
        {
            return data == current->data;
        }
        else if ((current->left != nullptr) && (current->right == nullptr))
        {
            if (current->data == data)
            {
                return true;
            }
            return this->exists(data, current->left);
        }
        else if ((current->left == nullptr) && (current->right != nullptr))
        {
            if (current->data == data)
            {
                return true;
            }
            return this->exists(data, current->right);
        }
        else
        {
            if (current->data == data)
            {
                return true;
            }
            return (this->exists(data, current->left) || this->exists(data, current->right));
        }
    }

    void print()

    {
        if (this->isEmpty())
        {
            cout << "[]\n";
            return;
        }

        cout << "[";
        this->_print();
        cout << "]\n";
    }






    void remove_value(int value, Node *current = nullptr)
    {
        if (current == nullptr)
        {
            if (this->head->data == value)
            {
                this->head = nullptr;
                return;
            }
            else{
                this->remove_value(value, this->head);
                return;
            }
        }
        else
        {
            if (current->left != nullptr)
            {
                if (current->left->data == value)
                {
                    cout << current->data << "      nel lato sinistro\n" ;
                    return;
                }
                else
                {
                    // cout << current->data << " Vado nel lato sinistro -> "<< current->left->data << endl ;
                    cout << current->left->data << "\t<-----\t"<< current->data << endl   ;
                    this->remove_value(value, current->left);
                    
                }
                
            }
            
            if (current->right != nullptr) 
            {
                if (current->data == value)
                {
                    cout << current->data  << "     nel lato destro\n";
                }
                else
                { 
                    cout << "\t\t" << current->data << " ---->  "<< current->right->data << endl ;
                    this->remove_value(value, current->right);
                }
                
            }

            if((current->left == nullptr) && (current->right == nullptr))
            {
                if (current->data == value)
                {
                    cout << "\t\t\t\t\t" << current->data << " <- returned\n";
                    return;
                }
                else
                {
                    cout << "\t\t\t\t\t" << current->data << "\n";
                    return;
                }
                
                return;
            }            
        }
    }
};





void test_remove()
{
    BinaryTree bn;
    bn.push(10);
    // bn.print();
    bn.push(8);
    // bn.remove_value(8); // il primo si rimuove OK!
    bn.push(87);
    bn.push(21);
    bn.push(32);
    bn.push(6);
    bn.push(2);
    bn.push(25);
    bn.push(64);
    bn.push(85);
    bn.push(19);
    bn.push(11);
    bn.push(38);
    bn.push(9);
    bn.remove_value(6);

    bn.print();
    // bn.print();
}

void test_init()
{
    BinaryTree bn;
    bn.print();
    cout << "\n\n  is empty -> " << bn.isEmpty() << "\n\n";
    bn.push(10);
    cout << "\n\n  is empty -> " << bn.isEmpty() << "\n\n";
    bn.push(11);
    bn.push(87);
    bn.push(21);
    bn.push(32);
    bn.print();
    bn.push(6);
    bn.push(19);
    bn.push(38);
    bn.push(9);
    bn.push(14);
    bn.push(2);
    bn.push(4);
    bn.push(6);
    bn.print();
    bn.push(3);
    bn.push(712);
    bn.push(5);
    bn.print();
    bn.push(23);
    bn.push(12);
    bn.push(13);
    cout << "\n\n  exists(712) -> " << bn.exists(712) << "\n";
    cout << "\n\n  Min  ->   " << bn.getMin() << "\n";
    cout << "  Max   ->  " << bn.getMax() << "\n\n\n";
    bn.print();
}

int main()
{
    // system("python3");
    system("clear");
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n\n\n ";
    test_remove();
    cout << "\n\n------------------------------------\n\n";
    return 0;
}
