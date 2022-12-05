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

public:
    Node *head;

    BinaryTree(/* args */)
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
                        // cout << "right Dato registrato " << current->data << endl;
                        break;
                    }
                    else
                    {
                        // cout << "right passato per " << current->data << "\n";
                        current = current->right;
                    }
                }
                else
                {

                    if (current->left == nullptr)
                    {
                        current->left = new Node(data);
                        // cout << "left Dato registrato " << current->data << endl;
                        break;
                    }
                    else
                    {
                        // cout << "left passato per " << current->data << "\n";
                        current = current->left;
                    }
                }
            }
        }
    }

    void print(Node *current = nullptr)
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

        if (current->right !=nullptr)
        {
            cout << current->data << ", ";
            this->print(current->right);     
        }
        if (current->left !=nullptr)
        {
            cout << current->data << ", ";
            this->print(current->left);
             
        }

    }
};

void test_init()
{
    BinaryTree bn;
    bn.push(1);
    bn.push(10);
    bn.push(2);
    bn.push(4);
    bn.push(14);
    bn.push(6);
    bn.push(3);
    bn.push(7);
    bn.push(11);
    bn.push(8);
    bn.push(5);
    bn.push(12);
    bn.push(13);
    bn.push(9);
    bn.print();
}

int main()
{

    test_init();
    return 0;
}
