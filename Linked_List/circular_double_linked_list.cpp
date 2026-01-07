#include <iostream>
#include <string>

using namespace std;

class Node
{
    int data;
    Node *nextAddr;
    Node *prevAddr;

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

    Node(int d, Node *next, Node *prev)
    {
        data = d;
        nextAddr = next;
        prevAddr = prev;
    }

    int getData() { return data; }
    Node *getNextAddress() { return nextAddr; }
    Node *getPrevAddress() { return prevAddr; }

    void setData(int d) { data = d; }
    void setNextAddr(Node *addr) { nextAddr = addr; }
    void setPrevAddr(Node *addr) { prevAddr = addr; }
};

class DCLL
{

    Node *head;
    Node *current;
    int nov;

public:
    DCLL()
    {
        head = NULL;
        current = NULL;
        nov = 0;
    }

    Node *getHead() { return head; }

    // insert section

    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            head->setNextAddr(head); // Points to itself
            head->setPrevAddr(head); // Points to itself
        }
        else
        {
            Node *tail = head->getPrevAddress(); // In Circular, head->prev is Tail

            newNode->setNextAddr(head);
            newNode->setPrevAddr(tail);

            head->setPrevAddr(newNode);
            tail->setNextAddr(newNode);

            head = newNode; // Move head to new node
        }
        nov++;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            head->setNextAddr(head);
            head->setPrevAddr(head);
        }
        else
        {
            Node *tail = head->getPrevAddress(); // Fast access to tail

            newNode->setNextAddr(head);
            newNode->setPrevAddr(tail);

            tail->setNextAddr(newNode);
            head->setPrevAddr(newNode);
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

        // If inserting after the last element (loc = nov + 1)
        if (loc == nov + 1)
        {
            insertAtEnd(val);
            return;
        }

        current = head;
        for (int i = 1; i < loc - 1; i++)
        {
            current = current->getNextAddress();
            // Safety check if loc is totally out of bounds (though nov check handles most)
            if (current == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }

        // Insert between current and current->next
        Node *newNode = new Node(val, current->getNextAddress(), current);

        current->getNextAddress()->setPrevAddr(newNode);
        current->setNextAddr(newNode);
        nov++;
    }

    // delete section

    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        current = head;

        // Case: Only one node
        if (head->getNextAddress() == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *tail = head->getPrevAddress();
            head = head->getNextAddress();

            head->setPrevAddr(tail);
            tail->setNextAddr(head);

            delete current;
        }
        nov--;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        // Case: Only one node
        if (head->getNextAddress() == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            current = head->getPrevAddress(); // Direct access to tail
            Node *newTail = current->getPrevAddress();

            newTail->setNextAddr(head);
            head->setPrevAddr(newTail);

            delete current;
        }
        nov--;
    }

    void deleteAtSpecificLocation(int loc)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (loc <= 0 || loc > nov)
        {
            cout << "\tInvalid position" << endl;
            return;
        }

        if (loc == 1)
        {
            deleteAtStart();
            return;
        }

        if (loc == nov)
        {
            deleteAtEnd();
            return;
        }

        current = head;
        for (int i = 1; i < loc; i++)
        {
            current = current->getNextAddress();
        }

        // Unlink current node
        current->getPrevAddress()->setNextAddr(current->getNextAddress());
        current->getNextAddress()->setPrevAddr(current->getPrevAddress());

        delete current;
        nov--;
    }

    // display section

    void displayData()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        current = head;
        do
        {
            cout << "Val: " << current->getData() << endl;
            current = current->getNextAddress();
        } while (current != head); // Stop when we circle back to head
    }

    void displayInReverseOrder()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        current = head->getPrevAddress(); // Start at Tail
        Node *stopNode = current;

        cout << "--- Reverse Display ---" << endl;
        // Iterate backwards until we hit tail again (meaning we circled fully)
        // Or simply do-while != tail
        do
        {
            cout << "Val: " << current->getData() << endl;
            current = current->getPrevAddress();
        } while (current != head->getPrevAddress());
    }

    void displayHelper(Node *n)
    {
        // Recursion in circular list is tricky without a stop condition passed as arg.
        // Simplified wrapper to prevent infinite recursion
        static Node *startNode = NULL;

        if (n == NULL)
            return;
        if (startNode == NULL)
            startNode = n; // Set start on first call
        else if (n == startNode)
        {                     // Wrapped around
            startNode = NULL; // Reset for next usage
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
            return;
        }

        current = head;
        do
        {
            if (current->getData() % 2 == 0)
                cout << "Val: " << current->getData() << endl;
            current = current->getNextAddress();
        } while (current != head);
    }

    void displayOnlyOdd()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        current = head;
        do
        {
            if (current->getData() % 2 != 0)
                cout << "Val: " << current->getData() << endl;
            current = current->getNextAddress();
        } while (current != head);
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
        do
        {
            if (current->getData() == val)
            {
                found = true;
                break;
            }
            current = current->getNextAddress();
        } while (current != head);

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
        do
        {
            if (current->getData() == val)
                count++;
            current = current->getNextAddress();
        } while (current != head);

        if (count == 0)
            cout << "There is no matching number" << endl;
        else
            cout << "There are " << count << " matching numbers" << endl;
    }

    void countValueAndLocation(int val)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        DCLL locList;
        int count = 0;
        int location = 1;
        current = head;

        do
        {
            if (current->getData() == val)
            {
                count++;
                locList.insertAtEnd(location);
            }
            location++;
            current = current->getNextAddress();
        } while (current != head);

        if (count == 0)
            cout << "There is no matching value" << endl;
        else
        {
            cout << "Here are the locations on which your value is found" << endl;
            locList.displayData();
        }
    }

    // Swap Section - Updated for Circular Logic

    void swapByValue(int val1, int val2)
    {
        if (head == NULL || head->getNextAddress() == head)
            return;
        if (val1 == val2)
            return;

        Node *node1 = NULL, *node2 = NULL;
        current = head;

        // Find nodes
        do
        {
            if (current->getData() == val1)
                node1 = current;
            if (current->getData() == val2)
                node2 = current;
            current = current->getNextAddress();
        } while (current != head);

        if (node1 == NULL || node2 == NULL)
            return;

        // Standardize logic (Reuse generic DLL swap logic + Head updates)

        // Adjacent Check (1->2)
        if (node1->getNextAddress() == node2)
        { /* Order is good */
        }
        else if (node2->getNextAddress() == node1)
        {
            Node *temp = node1;
            node1 = node2;
            node2 = temp;
        }

        Node *prev1 = node1->getPrevAddress();
        Node *next2 = node2->getNextAddress();

        // Check if adjacent
        if (node1->getNextAddress() == node2)
        {
            node1->setNextAddr(next2);
            node1->setPrevAddr(node2);

            node2->setNextAddr(node1);
            node2->setPrevAddr(prev1);

            next2->setPrevAddr(node1);
            prev1->setNextAddr(node2);
        }
        else // Not adjacent
        {
            Node *prev2 = node2->getPrevAddress();
            Node *next1 = node1->getNextAddress();

            node1->setNextAddr(next2);
            node1->setPrevAddr(prev2);

            node2->setNextAddr(next1);
            node2->setPrevAddr(prev1);

            next1->setPrevAddr(node2);
            prev1->setNextAddr(node2);

            next2->setPrevAddr(node1);
            prev2->setNextAddr(node1);
        }

        // Fix Head pointer if we swapped the head node
        if (head == node1)
            head = node2;
        else if (head == node2)
            head = node1;

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

        // Circular lists can loop, so we assume loc is within 1 to nov range
        if (loc1 > nov || loc2 > nov)
        {
            cout << "Invalid location" << endl;
            return;
        }

        Node *node1 = head;
        for (int i = 1; i < loc1; i++)
            node1 = node1->getNextAddress();

        Node *node2 = head;
        for (int i = 1; i < loc2; i++)
            node2 = node2->getNextAddress();

        // Reuse swap logic details...
        // ... (Logic is identical to swapByValue after nodes are found) ...

        // Note: For brevity, calling swapByValue's logic here logic explicitly
        // In production code, you would make a private "swapNodes(Node* a, Node* b)" helper function.

        // Simplified approach for this exercise: Call swapByValue (assuming unique values)
        // OR paste the swap block from above.
        // I will paste the swap block for correctness.

        Node *prev1 = node1->getPrevAddress();
        Node *next2 = node2->getNextAddress();

        if (node1->getNextAddress() == node2)
        {
            node1->setNextAddr(next2);
            node1->setPrevAddr(node2);
            node2->setNextAddr(node1);
            node2->setPrevAddr(prev1);
            next2->setPrevAddr(node1);
            prev1->setNextAddr(node2);
        }
        else
        {
            Node *prev2 = node2->getPrevAddress();
            Node *next1 = node1->getNextAddress();
            node1->setNextAddr(next2);
            node1->setPrevAddr(prev2);
            node2->setNextAddr(next1);
            node2->setPrevAddr(prev1);
            next1->setPrevAddr(node2);
            prev1->setNextAddr(node2);
            next2->setPrevAddr(node1);
            prev2->setNextAddr(node1);
        }

        if (head == node1)
            head = node2;
        else if (head == node2)
            head = node1;

        cout << "Swapped successfully" << endl;
    }

    void concatLists(DCLL &obj)
    {
        if (head == NULL)
        {
            cout << "First list empty" << endl;
            return;
        }
        if (obj.head == NULL)
        {
            cout << "Second list empty" << endl;
            return;
        }

        Node *tail1 = head->getPrevAddress();
        Node *tail2 = obj.head->getPrevAddress();

        // Connect End of List 1 -> Start of List 2
        tail1->setNextAddr(obj.head);
        obj.head->setPrevAddr(tail1);

        // Connect End of List 2 -> Start of List 1 (Circular closure)
        tail2->setNextAddr(head);
        head->setPrevAddr(tail2);

        // Update counts
        nov += obj.nov;
    }

    ~DCLL()
    {
        if (head == NULL)
            return;

        // Break the circle first to avoid infinite loop deletion
        Node *tail = head->getPrevAddress();
        tail->setNextAddr(NULL);

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
    // Test logic here
    return 0;
}