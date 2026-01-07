#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

// Special markers
const string EMPTY = "0000";
const string DELETED = "XXXX";

class HashTable
{
    string arr[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
            arr[i] = EMPTY;
    }

    // Changed int8_t to int to prevent overflow (ASCII sum > 127)
    int h1(int key)
    {
        return key % SIZE;
    }

    // Fixed Syntax Error ('int int' -> 'int key')
    int h2(int key)
    {
        // Must return non-zero.
        // Logic: 1 + (key % 4) returns 1, 2, 3, or 4. Safe.
        return 1 + (key % (SIZE - 1));
    }

    void insert(string uv)
    {
        int ascii = 0;
        for (char c : uv)
            ascii += c;

        int index = h1(ascii);
        int step = h2(ascii);
        int start = index;

        // Loop while slot is Occupied (Not Empty AND Not Deleted)
        while (arr[index] != EMPTY && arr[index] != DELETED)
        {
            // Double Hashing Logic
            index = (index + step) % SIZE;

            if (index == start)
            {
                cout << "Unable to insert. Table is full" << endl;
                return;
            }
        }

        arr[index] = uv;
        cout << "Value inserted successfully at index " << index << endl;
    }

    void removeValue(string uv)
    {
        int ascii = 0;
        for (char c : uv)
            ascii += c;

        int index = h1(ascii);
        int step = h2(ascii); // MUST use h2, same as insert!
        int start = index;

        // Stop if we hit a true EMPTY slot
        while (arr[index] != EMPTY)
        {
            // If found match (compare returns 0)
            if (arr[index].compare(uv) == 0)
            {
                arr[index] = DELETED; // Mark as DELETED, not EMPTY
                cout << "Value removed successfully" << endl;
                return;
            }

            index = (index + step) % SIZE;

            if (index == start)
                break;
        }

        cout << "Value not found" << endl;
    }

    void showData()
    {
        for (int i = 0; i < SIZE; i++)
        {
            // Show data if it's not Empty and not Deleted
            if (arr[i] != EMPTY && arr[i] != DELETED)
                cout << "Index[" << i << "] = " << arr[i] << endl;
            else if (arr[i] == DELETED)
                cout << "Index[" << i << "] = DELETED" << endl;
            else
                cout << "Index[" << i << "] = EMPTY" << endl;
        }
        cout << endl;
    }
};

int main()
{
    HashTable ht;
    ht.insert("ABC");
    ht.insert("BAC"); // Likely collision with ABC depending on Hash
    ht.showData();

    ht.removeValue("ABC");
    ht.showData();

    return 0;
}