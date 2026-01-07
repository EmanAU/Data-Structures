#include <iostream>
using namespace std;

class Stack
{

    int *arr;
    int size;
    int top;

public:
    void setSize(int s)
    {
        arr = new int[s];
        size = s;
        top = -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "The stack is full" << endl;
            return;
        }

        arr[++top] = data;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return -1;
        }
        return arr[top--]; // compiler will make a temp variable
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return;
        }
        return arr[top];
    }
};

int main()
{

    return 0;
}