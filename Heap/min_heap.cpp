#include <iostream>

using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MinHeap(int cap)
    {
        capacity = cap;
        arr = new int[cap];
        size = 0;
    }

    void insert(int v)
    {
        if (size == capacity)
        {
            cout << "Heap is full, can't insert more" << endl;
            return;
        }
        int i = size;
        arr[size] = v;
        size++;

        while (i != 0 && arr[i] < arr[(i - 1) / 2])
        {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;

            i = (i - 1) / 2;
        }

        cout << "Value has been inserted successfully" << endl;
    }

    int getMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return arr[0];
    }

    int extractMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        int i = 0;

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallestIndex = i;

            if (left < size && arr[left] < arr[smallestIndex])
                smallestIndex = left;

            if (right < size && arr[right] < arr[smallestIndex])
                smallestIndex = right;

            if (smallestIndex == i)
                break;

            int temp = arr[i];
            arr[i] = arr[smallestIndex];
            arr[smallestIndex] = temp;

            i = smallestIndex;
        }

        return root;
    }
};

int main()
{

    return 0;
}
