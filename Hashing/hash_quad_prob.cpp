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

    void insert(int uv)
    {
        if (isFull())
        {
            cout << "Table is full. Unable to isnert more values" << endl;
            return;
        }

        int index = HashFunction(uv);
        int i = 1;
        while (arr[index] != -1)
        {
            index = ((i * i) + index) % SIZE;
            i++;
        }
        arr[index] = uv;
        cout << "Value inserted successfully" << endl;
    }

    void removeData(int uv)
    {
        int i = 1;
        int index = HashFunction(uv);

        while (arr[index] != -1)
        {
            index = ((i * i) + index) % SIZE;
            i++;

            if (i > SIZE)
            {
                cout << "Value not found" << endl;
                return;
            }

            arr[index] = -1;
            cout << "Valude deleted successfully" << endl;
        }
    }

    void showData()
    {
        if (isEmpty())
        {
            cout << "The table is empty" << endl;
            return;
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] != -1)
            {
                cout << "Index[" << i << "]: " << arr[i] << endl;
            }
        }
        cout << endl;
    }
};

int main()
{

        return 0;
}