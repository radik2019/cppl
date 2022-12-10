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

    void _removeAndPush(Node *current = nullptr, bool removed = false)
    {
        if (removed)
        {
            this->push(current->data);
            if (current->left != nullptr)
            {
                this->_removeAndPush(current->left, true);
            }
            if (current->right != nullptr)
            {
                this->_removeAndPush(current->right, true);
            }
        }
        else
        {
            if (current->left != nullptr)
            {
                this->_removeAndPush(current->left, true);
            }
            if (current->right != nullptr)
            {
                this->_removeAndPush(current->right, true);
            }
        }
    }

    void condition_print(Node *current)
    {
        if (current->data == this->getMax())
        {
            cout << current->data << "";
        }
        else
        {
            cout << current->data << ", ";
        }
    }

    void _print(Node *current = nullptr)
    {
        if (current == nullptr)
        {
            current = this->head;
        }

        if ((current->left == nullptr) && (current->right == nullptr))

        {
            this->condition_print(current);
            return;
        }

        if ((current->left != nullptr) && (current->right == nullptr))
        {
            this->_print(current->left);
            this->condition_print(current);
        }
        else if ((current->left == nullptr) && (current->right != nullptr))
        {
            this->condition_print(current);
            this->_print(current->right);
        }
        else
        {
            this->_print(current->left);
            this->condition_print(current);
            this->_print(current->right);
        }
    }

    void _print_reverse(Node *current = nullptr)
    {
        if (current == nullptr)
        {
            current = this->head;
        }
        if ((current->left == nullptr) && (current->right == nullptr))
        {
            if (current->data == this->getMin())
            {
                cout << current->data << "";
                return;
            }

            cout << current->data << ", ";
            return;
        }
        else if ((current->left != nullptr) && (current->right == nullptr))
        {
            cout << current->data << ", ";
            this->_print_reverse(current->left);
        }
        else if ((current->left == nullptr) && (current->right != nullptr))
        {
            this->_print_reverse(current->right);
            cout << current->data << ", ";
        }
        else
        {
            this->_print_reverse(current->right);
            cout << current->data << ", ";
            this->_print_reverse(current->left);
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
                if (data >= current->data)
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

    int getMax()
    {
        Node *current = this->head;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current->data;
    }

    int getMin()
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

    void print(bool reverse = true)
    {
        if (reverse)
        {
            cout << "REVERSED\n";
            if (this->isEmpty())
            {
                cout << "[]\n";
                return;
            }
            cout << "[";
            this->_print_reverse();
            cout << "]\n";
        }
        else
        {
            cout << "NORMAL\n";
            if (this->isEmpty())
            {
                cout << "[]\n";
                return;
            }

            cout << "[";
            this->_print();
            cout << "]\n";
        }
    }

    void remove_value(int value, Node *current = nullptr)
    {
        if (current == nullptr)
        {
            if (this->head->data == value)
            {
                bool headIsInitialized = false;
                Node *temp_left = this->head->left;
                Node *temp_right = this->head->right;
                this->head = nullptr;
                if (temp_left != nullptr)
                {
                    this->head = new Node(temp_left->data);
                    headIsInitialized = true;
                    this->_removeAndPush(temp_left, true);
                }
                if (temp_right != nullptr)
                {
                    if (!headIsInitialized)
                    {
                        this->head = new Node(temp_right->data);
                    }
                    this->_removeAndPush(temp_right, true);
                }
                return;
            }
            else
            {
                this->remove_value(value, this->head);
                return;
            }
        }
        else
        {
            if (value > current->data)
            {
                if (current->right != nullptr)
                {
                    if (current->right->data == value)
                    {
                        Node *temp_right = current->right;
                        current->right = nullptr;
                        this->_removeAndPush(temp_right);
                        return;
                    }
                    this->remove_value(value, current->right);
                    return;
                }
            }
            else if (value < current->data)
            {
                if (current->left != nullptr)
                {
                    if (current->left->data == value)
                    {
                        Node *temp_left = current->left;
                        current->left = nullptr;
                        this->_removeAndPush(temp_left);
                        return;
                    }
                    this->remove_value(value, current->left);
                    return;
                }
                return;
            }
            else if (value == current->data)
            {
                cout << "   ===    " << current->data << "\n";
            }
        }
    }

    void printFlowTree(Node *current = nullptr)
    {
        if (current == nullptr)
        {
            current = this->head;
        }
        if ((current->left == nullptr) && (current->right == nullptr))
        {
            return;
        }

        if ((current->right != nullptr))
        {
            this->printFlowTree(current->right);
            if ((current->right->left == nullptr) and (current->right->right == nullptr))
            {
                cout << "\t\t" << current->data << "\t+=>\t" << current->right->data << endl;
            }
            else
            {
                cout << "\t\t" << current->data << "\t==>\t" << current->right->data << endl;
            }
        }
        if (current->left != nullptr)
        {
            this->printFlowTree(current->left);
            if ((current->left->left == nullptr) and (current->left->right == nullptr))
            {
                cout << current->left->data << "\t<=+=\t" << current->data << endl;
            }
            else
            {
                cout << current->left->data << "\t<==\t" << current->data << endl;
            }
        }
    }
};

BinaryTree *get_bin_tree()
{
    BinaryTree *bn = new BinaryTree;
    int lst[] = {10, 8, 87, 21, 32, 6, 2, 25, 64, 85, 19, 11, 38, 9};
    for (auto &&i : lst)
    {
        bn->push(i);
    }
    return bn;
}

void test_remove()
{
    BinaryTree *bn = get_bin_tree();

    bn->print();
    bn->remove_value(21);
    bn->print();
    bn->remove_value(10);
    cout << "exists   9   " << bn->exists(9) << endl;

    bn->print();
}

void test_init()
{
    BinaryTree bn;
    bn.print();
    cout << "  is empty -> " << bn.isEmpty() << "\n";
    bn.push(10);
    cout << "  is empty -> " << bn.isEmpty() << "\n";
    bn.push(11);
    bn.push(87);
    bn.push(21);
    bn.push(32);
    bn.print();
    cout << "  Max   ->  " << bn.getMax() << "\n";
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
    bn.remove_value(32);
    cout << "  exists(712) -> " << bn.exists(712) << "\n";
    cout << "  Min  ->   " << bn.getMin() << "\n";
    cout << "  Max   ->  " << bn.getMax() << "\n";
    bn.print();
}

void test_print()
{
    BinaryTree *bn = get_bin_tree();
    bn->print();
    bn->print(0);
    cout << bn->getMax();
}

void test_printFlowTree()
{
    BinaryTree *bn = get_bin_tree();
    bn->printFlowTree();
}

int main()
{
    // system("python3");
    system("clear");
    cout << "\n------------------------------------\n\n";
    test_printFlowTree();
    test_init();
    test_print();
    test_remove();
    cout << "\n------------------------------------\n\n";
    return 0;
}

