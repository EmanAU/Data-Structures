#include <iostream>
#include <string>
using namespace std;

class CircularQueue
{
    int front, rear, size;
    string *calls;

public:
    CircularQueue(int s)
    {
        size = s;
        calls = new string[s];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        // Queue is full if rear is just behind front (circularly)
        return ((front == 0 && rear == size - 1) || (rear + 1) % size == front);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void addCall(string callName)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot add: " << callName << endl;
            return;
        }

        // First element insertion
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            // Circular increment
            rear = (rear + 1) % size;
        }

        calls[rear] = callName;
        cout << "Call added: " << callName << endl;
    }

    void answerCall()
    {
        if (isEmpty())
        {
            cout << "No calls waiting." << endl;
            return;
        }

        // Capture data BEFORE resetting pointers
        string answered = calls[front];
        cout << "Answered call: " << answered << endl;

        // If this was the last element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // Circular increment
            front = (front + 1) % size;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Pending Calls: " << endl;
        int i = front;
        while (true)
        {
            cout << "\t" << calls[i] << endl;

            // Break if we just printed the rear element
            if (i == rear)
                break;

            // Circular increment
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    // Test Code
    CircularQueue q(5);

    q.addCall("Client A");
    q.addCall("Client B");
    q.addCall("Client C");
    q.addCall("Client D");
    q.addCall("Client E");

    q.displayQueue();

    q.answerCall(); // Answers Client A
    q.answerCall(); // Answers Client B

    q.addCall("Client F"); // Should wrap around to index 0

    q.displayQueue(); // Should show C, D, E, F

    return 0;
}