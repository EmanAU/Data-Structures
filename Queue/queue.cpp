#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class myQ
{
    int f, r, size, *arr;

public:
    myQ(int s)
    {
        f = -1;
        r = -1;
        size = s;
        arr = new int[s];
        for (int i = 0; i < size; i++)
            arr[i] = -1;
    }

    bool isFull()
    {
        return r == size - 1;
    }

    bool isEmpty()
    {
        return f == -1 || f > r;
    }

    void enqueue(int v)
    {
        if (isFull())
        {
            cout << "\tThe queue is full" << endl;
        }
        else
        {
            if (r == -1)
                f = 0; // Initialize front on first insert
            arr[++r] = v;
            cout << "\tValue added successfully" << endl;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "\tThe queue is empty" << endl;
            return -1; // FIXED: Must return a value
        }
        else
        {
            int temp = arr[f];
            arr[f] = -1;
            f++;

            // If queue becomes empty, reset pointers to reusable state
            if (f > r)
            {
                f = -1;
                r = -1;
            }

            return temp;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\tThe queue is empty" << endl;
        }
        else
        {
            // FIXED: Only loop from front to rear
            for (int i = f; i <= r; i++)
            {
                cout << "\t" << arr[i] << endl;
            }
        }
    }

    // Add Destructor to prevent memory leak
    ~myQ()
    {
        delete[] arr;
    }
};

int main()
{

    return 0;
}