#include <iostream>
using namespace std;

class Node
{
    Node *next;
    int data;

public:
    Node()
    {
        next = NULL;
    }

    void setData(int d) { data = d; }
    int getData() { return data; }
    void setNextAddr(Node *addr) { next = addr; }
    Node *getNextAddr() { return next; }
};

class Stack
{
    Node *head;
    Node *current;

public:
    Stack()
    {
        head = NULL;
        current = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        Node *nn = new Node;
        nn->setData(data);
        nn->setNextAddr(head);
        head = nn;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return -1;
        }
        current = head;
        int temp = current->getData();
        head = head->getNextAddr(); // 1st step done
        delete current;
        current = NULL; // This is a good practice
        return temp;    // final step;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return -1;
        }
        return head->getData();
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{

    return 0;
}