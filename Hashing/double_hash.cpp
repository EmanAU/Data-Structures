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
            arr[i] = -1;
    }

    int h1(int key)
    {
        return key % SIZE;
    }

    int h2(int key)
    {
        return 1 + (key % (SIZE - 1));
    }

    void insert(int uv)
    {
        int index = h1(uv);
        int start = index;

        while (arr[index] != -1)
        {
            index = (index + h2(uv) % SIZE);

            if (index == start)
            {
                cout << "Unable to insert. Table is full" << endl;
                return;
            }
        }

        arr[index] = uv;
        cout << "Value inserted successfully" << endl;
    }

    void removeValue(int uv)
    {
        int index = h1(uv);
        int step = h2(uv);
        int start = index;

        while (arr[index] != -1)
        {
            if (arr[index] == uv)
            {
                arr[index] = -1; // your chosen logic
                cout << "Value removed successfully" << endl;
                return;
            }

            index = (index + h2(uv) % SIZE);

            if (index == start)
                break;
        }

        cout << "Value not found" << endl;
    }

    void showData()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] != -1)
                cout << "Index[" << i << "] = " << arr[i] << endl;
        }
        cout << endl;
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

    table.removeValue(30);
    table.showData();

    return 0;
}
