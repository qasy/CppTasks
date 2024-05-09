#include <iostream>

class List
{
public:
    List()
    {
        this->head = nullptr;
        this->size = 0;
    }

    void push_back(int value)
    {
        if (!head)
        {
            head = new Node(value);
            ++size;
            return;
        }

        Node* current = this->head;
        while (current->pNext)
        {
            current = current->pNext;
        }
        current->pNext = new Node(value);
        ++size;
    }

    // int& operator[](int i)
    // {

    //     Node* current = head;
    //     int idx       = 0;
    //     while (current)
    //     {
    //         if (idx == i)
    //         {
    //             return current->data;
    //         }

    //         if (current->pNext)
    //         {
    //             current = current->pNext;
    //         }
    //         else
    //         {
    //             std::cout << std::endl;
    //             return;
    //         }
    //     }
    // }

    void print() const
    {
        Node* current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->pNext;
        }
        std::cout << std::endl;
    }

    int getSize()
    {
        return this->size;
    }

private:
    class Node
    {
    public:
        Node(int data = 0, Node* p = nullptr)
        {
            this->data  = data;
            this->pNext = p;
        }
        int data;
        Node* pNext;
    };

    Node* head;
    int size;
};

int main()
{
    List l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(52);
    l.push_back(2);
    l.print();
    std::cout << l.getSize() << std::endl;

    return 0;
}