#include <iostream>
#include <string>

using namespace std;

class Node
{
    int data;
    Node *nextAddr;
    Node *prevAddr; // NEW: Pointer to previous node

public:
    Node()
    {
        data = 0;
        nextAddr = NULL;
        prevAddr = NULL;
    }

    Node(int d)
    {
        data = d;
        nextAddr = NULL;
        prevAddr = NULL;
    }

    // specific constructor for inserting in middle
    Node(int d, Node *next, Node *prev)
    {
        data = d;
        nextAddr = next;
        prevAddr = prev;
    }

    int getData() { return data; }
    Node *getNextAddress() { return nextAddr; }
    Node *getPrevAddress() { return prevAddr; } // NEW Getter

    void setData(int d) { data = d; }
    void setNextAddr(Node *addr) { nextAddr = addr; }
    void setPrevAddr(Node *addr) { prevAddr = addr; } // NEW Setter
};

class DLL
{

    Node *head;
    Node *current;
    int nov;

public:
    DLL()
    {
        head = NULL;
        current = NULL;
        nov = 0;
    }

    Node *getHead() { return head; }

    // insert section

    void insertAtStart(int val)
    {
        Node *newNode = new Node(val); // prev and next are NULL by default

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->setNextAddr(head);
            head->setPrevAddr(newNode); // Link back
            head = newNode;
        }
        nov++;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current = head;
            while (current->getNextAddress() != NULL)
            {
                current = current->getNextAddress();
            }

            current->setNextAddr(newNode);
            newNode->setPrevAddr(current); // Link back
        }
        nov++;
    }

    void insertAtSpecificLocation(int loc, int val)
    {
        if (loc <= 0)
        {
            cout << "Invalid Location" << endl;
            return;
        }

        if (loc == 1)
        {
            insertAtStart(val);
            return;
        }

        current = head;
        for (int i = 1; i < loc - 1 && current != NULL; i++)
        {
            current = current->getNextAddress();
        }

        if (current == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        // Create new node pointing Next to current->next, and Prev to current
        Node *newNode = new Node(val, current->getNextAddress(), current);

        // If there is a node AFTER the new one, link it back to new node
        if (current->getNextAddress() != NULL)
        {
            current->getNextAddress()->setPrevAddr(newNode);
        }

        current->setNextAddr(newNode);
        nov++;
    }

    // delete section

    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            current = head;
            head = head->getNextAddress();

            if (head != NULL) // If list is not empty after deletion
            {
                head->setPrevAddr(NULL);
            }

            delete current;
            nov--;
        }
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else if (head->getNextAddress() == NULL)
        {
            delete head;
            head = NULL;
            nov--;
        }
        else
        {
            current = head;
            while (current->getNextAddress() != NULL)
            {
                current = current->getNextAddress();
            }

            // current is now the last node
            current->getPrevAddress()->setNextAddr(NULL); // Set 2nd last node's next to NULL
            delete current;
            nov--;
        }
    }

    void deleteAtSpecificLocation(int loc)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (loc <= 0)
        {
            cout << "\tInvalid position" << endl;
            return;
        }

        if (loc == 1)
        {
            deleteAtStart();
            return;
        }

        current = head;
        // In DLL we can just find the exact node, we don't strictly need "previous" logic
        // but keeping your loop style for consistency
        for (int i = 1; i < loc && current != NULL; i++)
        {
            current = current->getNextAddress();
        }

        if (current == NULL)
        {
            cout << "\tThis location doesn't exist" << endl;
            return;
        }

        // Unlink current node
        if (current->getPrevAddress() != NULL)
        {
            current->getPrevAddress()->setNextAddr(current->getNextAddress());
        }

        if (current->getNextAddress() != NULL)
        {
            current->getNextAddress()->setPrevAddr(current->getPrevAddress());
        }

        delete current;
        nov--;
    }

    // display section

    void displayData()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            current = head;
            while (current != NULL)
            {
                cout << "Val: " << current->getData() << endl;
                current = current->getNextAddress();
            }
        }
    }

    // OPTIMIZED FOR DLL: No need to create a new list!
    void displayInReverseOrder()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        current = head;
        // Go to the last node
        while (current->getNextAddress() != NULL)
        {
            current = current->getNextAddress();
        }

        // Traverse backwards
        cout << "--- Reverse Display ---" << endl;
        while (current != NULL)
        {
            cout << "Val: " << current->getData() << endl;
            current = current->getPrevAddress();
        }
    }

    void displayHelper(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        displayHelper(n->getNextAddress());
        cout << "The value is " << n->getData() << endl;
    }

    void displayOnlyEven()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            current = head;
            while (current != NULL)
            {
                if (current->getData() % 2 == 0)
                {
                    cout << "Val: " << current->getData() << endl;
                }
                current = current->getNextAddress();
            }
        }
    }

    void displayOnlyOdd()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            current = head;
            while (current != NULL)
            {
                if (current->getData() % 2 != 0)
                {
                    cout << "Val: " << current->getData() << endl;
                }
                current = current->getNextAddress();
            }
        }
    }

    // search section

    void searchByValue(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        bool found = false;
        current = head;
        while (current != NULL)
        {
            if (current->getData() == val)
            {
                found = true;
                break;
            }
            current = current->getNextAddress();
        }

        if (found)
            cout << "The number is present in the list" << endl;
        else
            cout << "The number is not present in the list" << endl;
    }

    void countValue(int val)
    {
        int count = 0;

        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        current = head;

        while (current != NULL)
        {
            if (current->getData() == val)
                count++;
            current = current->getNextAddress();
        }

        if (count == 0)
            cout << "There is no matching number in the list" << endl;
        else if (count == 1)
            cout << "There is " << count << " matching number in the list" << endl;
        else
            cout << "There are " << count << " matching numbers in the list" << endl;
    }

    void countValueAndLocation(int val)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        DLL locList; // Using DLL now
        int count = 0;
        int location = 1;
        current = head;

        while (current != NULL)
        {
            if (current->getData() == val)
            {
                count++;
                locList.insertAtEnd(location);
            }
            location++;
            current = current->getNextAddress();
        }

        if (count == 0)
        {
            cout << "There is no matching value in the list" << endl;
            return;
        }
        else if (count == 1)
        {
            cout << "There is one matching value" << endl;
            cout << "Its location is " << locList.getHead()->getData() << endl;
        }
        else
        {
            cout << "Here are the locations on which your value is found" << endl;
            locList.displayData();
        }
    }

    // Swap Section - Updated for DLL Pointer Logic

    void swapByValue(int val1, int val2)
    {
        if (head == NULL || head->getNextAddress() == NULL)
            return;
        if (val1 == val2)
            return;

        Node *node1 = head;
        Node *node2 = head;

        while (node1 != NULL && node1->getData() != val1)
            node1 = node1->getNextAddress();
        while (node2 != NULL && node2->getData() != val2)
            node2 = node2->getNextAddress();

        if (node1 == NULL || node2 == NULL)
            return;

        // Determine if they are adjacent
        bool adjacent = (node1->getNextAddress() == node2) || (node2->getNextAddress() == node1);

        // Standardize: node1 should be the earlier node for logic simplicity if adjacent
        if (node1->getNextAddress() == node2)
        { /* already in order */
        }
        else if (node2->getNextAddress() == node1)
        {
            Node *temp = node1;
            node1 = node2;
            node2 = temp;
        }

        // Update predecessors
        Node *prev1 = node1->getPrevAddress();
        Node *prev2 = node2->getPrevAddress(); // If adjacent, this is node1

        Node *next1 = node1->getNextAddress(); // If adjacent, this is node2
        Node *next2 = node2->getNextAddress();

        // If adjacent (node1 -> node2)
        if (node1->getNextAddress() == node2)
        {
            node1->setNextAddr(next2);
            node1->setPrevAddr(node2);

            node2->setNextAddr(node1);
            node2->setPrevAddr(prev1);

            if (next2)
                next2->setPrevAddr(node1);
            if (prev1)
                prev1->setNextAddr(node2);
            else
                head = node2;
        }
        else
        {
            // Not adjacent
            node1->setNextAddr(next2);
            node1->setPrevAddr(prev2);

            node2->setNextAddr(next1);
            node2->setPrevAddr(prev1);

            if (next1)
                next1->setPrevAddr(node2);
            if (prev1)
                prev1->setNextAddr(node2);
            else
                head = node2;

            if (next2)
                next2->setPrevAddr(node1);
            if (prev2)
                prev2->setNextAddr(node1);
            else
                head = node1;
        }
        cout << "Swapped successfully" << endl;
    }

    void swapByLocation(int loc1, int loc2)
    {
        if (head == NULL)
            return;
        if (loc1 == loc2)
            return;
        if (loc2 < loc1)
            swap(loc1, loc2);

        Node *node1 = head;
        for (int i = 0; i < loc1 - 1 && node1 != NULL; i++)
            node1 = node1->getNextAddress();

        Node *node2 = head;
        for (int i = 0; i < loc2 - 1 && node2 != NULL; i++)
            node2 = node2->getNextAddress();

        if (node1 == NULL || node2 == NULL)
            return;

        // Reuse logic from swapByValue now that we found the nodes
        // (Re-implementing logic here for completeness based on your SLL structure)

        Node *prev1 = node1->getPrevAddress();
        Node *prev2 = node2->getPrevAddress();
        Node *next1 = node1->getNextAddress();
        Node *next2 = node2->getNextAddress();

        // Adjacent Check (1->2)
        if (node1->getNextAddress() == node2)
        {
            node1->setNextAddr(next2);
            node1->setPrevAddr(node2);
            node2->setNextAddr(node1);
            node2->setPrevAddr(prev1);

            if (next2 != NULL)
                next2->setPrevAddr(node1);
            if (prev1 != NULL)
                prev1->setNextAddr(node2);
            else
                head = node2;
        }
        else
        {
            // Non-Adjacent
            node1->setNextAddr(next2);
            node1->setPrevAddr(prev2);

            node2->setNextAddr(next1);
            node2->setPrevAddr(prev1);

            if (next1)
                next1->setPrevAddr(node2);
            if (prev1)
                prev1->setNextAddr(node2);
            else
                head = node2;

            if (next2)
                next2->setPrevAddr(node1);
            if (prev2)
                prev2->setNextAddr(node1);
        }
        cout << "Swapped successfully" << endl;
    }

    void concatLists(DLL &obj)
    {
        if (head == NULL)
        {
            cout << "The first list is empty" << endl;
            return;
        }
        if (obj.head == NULL)
        {
            cout << "The 2nd list is empty" << endl;
            return;
        }

        current = head;
        while (current->getNextAddress() != NULL)
        {
            current = current->getNextAddress();
        }

        // Link End of List 1 to Head of List 2
        current->setNextAddr(obj.head);

        // DLL Logic: Link Head of List 2 back to End of List 1
        obj.head->setPrevAddr(current);
    }

    ~DLL()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->getNextAddress();
            delete temp;
        }
    }
};

int main()
{
    // You can test the code here
    return 0;
}