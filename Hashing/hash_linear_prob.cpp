#include <iostream>
using namespace std;

const int SIZE = 5;

class HashTable
{
    int arr[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = -1;
        }
    }

    int HashFunction(int key)
    {
        return (key % SIZE);
    }

    void insert(int uv)
    {
        if (isFull())
        {
            cout << "The table is full. Unable to insert more data" << endl;
            return;
        }
        int index = HashFunction(uv);

        while (arr[index] != -1)
        {
            index = (index + 1) % SIZE;
        }

        arr[index] = uv;
        cout << "Value inserted successfully" << endl;
    }

    void removeValue(int uv)
    {
        int index = HashFunction(uv);
        int temp = index;

        while (arr[index] != uv)
        {
            index = (index + 1) % SIZE;
            if (index == temp)
            {
                cout << "Value not found" << endl;
                return;
            }
        }
        arr[index] = -1;
        cout << "Value removed successfully" << endl;
    }

    bool isFull()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] == -1)
                return false;
        }
        return true;
    }

    bool isEmpty()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] != -1)
                return false;
        }
        return true;
    }

    void showData()
    {
        if (isEmpty())
        {
            cout << "Table is empty. Nothing to show" << endl;
            return;
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] != -1)
            {
                cout << "Index[" << i << "]: " << arr[i] << endl;
            }
            cout << endl;
        }
    }
};

int main()
{

    HashTable table;

    table.insert(10);
    table.insert(20);
    table.insert(30);
    table.insert(40);
    table.insert(50);
    table.insert(60);

    table.removeValue(40);
    table.showData();

    return 0;
}