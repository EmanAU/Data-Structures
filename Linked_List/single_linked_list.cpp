#include <iostream>
#include <string>

using namespace std;

class Node
{
    int data;
    Node *nextAddr;

public:
    Node()
    {
        data = 0;
        nextAddr = NULL;
    }

    Node(int d)
    {
        data = d;
        nextAddr = NULL;
    }

    Node(Node *addr)
    {
        data = 0;
        nextAddr = addr;
    }

    Node(int d, Node *addr)
    {
        data = d;
        nextAddr = addr;
    }

    int getData() { return data; }
    Node *getNextAddress() { return nextAddr; }

    void setData(int d) { data = d; }
    void setNextAddr(Node *addr) { nextAddr = addr; }
};

class SLL
{

    Node *head;
    Node *current;
    int nov;

public:
    SLL()
    {
        head = NULL;
        current = NULL;
        nov = 0;
    } // SLL()

    Node *getHead() { return head; }

    // insert section

    void insertAtStart(int val)
    {
        Node *newNode = new Node;
        newNode->setData(val);
        newNode->setNextAddr(NULL);
        if (head == NULL)
        {
            head = newNode;
        } // if
        else
        {
            newNode->setNextAddr(head);
            head = newNode;
        } // else
        nov++;
    } // insertAtStart_function

    void insertAtEnd(int val)
    {

        Node *newNode = new Node;
        newNode->setData(val);
        newNode->setNextAddr(NULL);

        if (head == NULL)
        {
            head = newNode;
        } // if
        else
        {
            current = head;

            while (current->getNextAddress() != NULL)
            {
                current = current->getNextAddress();
            }
            current->setNextAddr(newNode);
        } // else
    } // insertAtEnd_function

    void insertAtSpecificLocation(int loc, int val)
    {

        if (loc <= 0)
        {
            cout << "Invalid Location" << endl;
            return;
        } // first if condition

        if (loc == 1)
        {
            Node *newNode = new Node;
            newNode->setData(val);
            if (head == NULL)
            {
                head = newNode;
            } // if
            else
            {
                newNode->setNextAddr(head);
                head = newNode;
            } // else
            nov++;
            return;
        } // second if condition

        current = head;
        for (int i = 1; i < loc - 1 && current != NULL; i++)
        {
            current = current->getNextAddress();
        } // for loop

        if (current == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        } // check if current is null

        Node *newNode = new Node(val, current->getNextAddress());
        current->setNextAddr(newNode);
        nov++;
    } // funciton insertAtSpecificLocation

    // delete section

    void deleteAtSpecificLocation(int loc)
    {

        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        } // if head is null

        if (loc <= 0)
        {
            cout << "\tInvalid position" << endl;
            return;
        } // if locaiton is negative or zero

        if (loc == 1)
        {
            deleteAtStart();
            return;
        } // if location is 1

        current = head;

        for (int i = 1; i < loc - 1 && current != NULL; i++)
        {
            current = current->getNextAddress();
        } // for loop

        if (current == NULL || current->getNextAddress() == NULL)
        {
            cout << "\tThis locaiton doesn't exist" << endl;
            return;
        } // if currnet is null means the location doesn't exist

        Node *temp = current->getNextAddress();
        current->setNextAddr(temp->getNextAddress()); // problem is with this line becuase temp is null pointer
        delete temp;
        nov--;
    } // funciton deleteAtSpecificLocation

    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        } // if
        else
        {
            current = head;
            head = head->getNextAddress();
            delete current;
            nov--;
        } // else
    } // delte atastart

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        } // if
        else if (head->getNextAddress() == NULL)
        {
            delete head;
            head = NULL;
            nov--;
            return;
        } // esle if
        else
        {
            current = head;

            Node *previous = NULL;
            while (current->getNextAddress() != NULL)
            {
                previous = current;
                current = current->getNextAddress();
            } // while

            previous->setNextAddr(NULL);
            delete current;
            nov--;
        } // else

    } // delete_function

    // display section

    void displayData()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        } // if
        else
        {
            current = head;
            while (current != NULL)
            {
                cout << "Val: " << current->getData() << endl;
                current = current->getNextAddress();
            } // while
        } // else
    }

    void displayInReverseOrder()
    {
        int count = 0;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        } // if head is empty

        SLL newList;
        current = head;
        while (current != NULL)
        {
            newList.insertAtStart(current->getData());
            current = current->getNextAddress();
        } // while loop

        newList.displayData();

    } // function displayInReverseOrder

    void displayHelper(Node *n)
    {
        if (n == NULL)
        {
            return;
        } // if condition
        displayHelper(n->getNextAddress());
        cout << "The value is " << n->getData() << endl;
    } // function to display the list through the recursive function

    void displayOnlyEven()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        } // if
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
            } // while
        } // else
    } // function displayOnlyEven

    void displayOnlyOdd()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        } // if
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
            } // while
        } // else
    } // function displayOnlyOdd

    // search section

    void searchByValue(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        } // if head is null

        bool found = false;
        current = head;
        while (current != NULL)
        {
            if (current->getData() == val)
            {
                found = true;
                break;
            } // if
            current = current->getNextAddress();
        } // while loop

        if (found)
            cout << "The number is present in the list" << endl;
        else
            cout << "The number is not present in the list" << endl;
    } // function searchByValue

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
        } // while loop

        if (count == 0)
        {
            cout << "There is no matching number in the list" << endl;
        } // if
        else if (count == 1)
        {
            cout << "Ther is " << count << " matching number in the list" << endl;
        } // else if
        else
        {
            cout << "There are " << count << " matching numbers in the list" << endl;
        } // else

    } // function countValue

    void countValueAndLocation(int val)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        } // if head is null

        SLL locList;
        int count = 0;
        int location = 1;
        current = head;

        while (current != NULL)
        {
            if (current->getData() == val)
            {
                count++;
                locList.insertAtEnd(location);
            } // if condition
            location++;
            current = current->getNextAddress();
        } // while loop

        if (count == 0)
        {
            cout << "There is no matching value in the list" << endl;
            return;
        } // if
        else if (count == 1)
        {
            cout << "Ther is one matching value" << endl;
            cout << "Its location is " << locList.getHead()->getData() << endl;
        } // else if
        else
        {
            cout << "Here are the locations on which your value is found" << endl;
            locList.displayData();
        } // else

    } // function countValueAndLocation

    // Swap Section

    void swapByValue(int val1, int val2)
    {

        if (head == NULL || head->getNextAddress() == NULL)
        {
            cout << "List doesn't has two elemetns" << endl;
            return;
        }

        if (val1 == val2)
        {
            cout << "Values can't be same" << endl;
            return;
        }

        Node *prev1 = NULL;
        Node *prev2 = NULL;
        Node *node1 = head;
        Node *node2 = head;

        while (node1 != NULL)
        {
            if (node1->getData() == val1)
                break;
            prev1 = node1;
            node1 = node1->getNextAddress();
        }

        while (node2 != NULL)
        {
            if (node2->getData() == val2)
                break;
            prev2 = node2;
            node2 = node2->getNextAddress();
        }

        if (node1 == NULL || node2 == NULL)
        {
            cout << "Location doesn't exist " << endl;
            return;
        }

        if (node1->getNextAddress() == node2)
        {
            node1->setNextAddr(node2->getNextAddress());
            node2->setNextAddr(node1);

            if (prev1 != NULL)
                prev1->setNextAddr(node2);
            else
                head = node2;

            cout << "Swapped successfully" << endl;
            return;
        } // adjacent case 1

        if (node2->getNextAddress() == node1)
        {
            node2->setNextAddr(node1->getNextAddress());
            node1->setNextAddr(node2);

            if (prev2 != NULL)
                prev2->setNextAddr(node1);
            else
                head = node1;

            cout << "Swapped successfully" << endl;
            return;
        } // adjacent case 2

        if (prev1 == NULL)
        {
            prev2->setNextAddr(node1);
            Node *temp = node2->getNextAddress();
            node2->setNextAddr(node1->getNextAddress());
            node1->setNextAddr(temp);
            head = node2;
            cout << "Successfully swapped" << endl;
            return;
        } // means node1 is head

        if (prev2 == NULL)
        {
            prev1->setNextAddr(node2);
            Node *temp = node1->getNextAddress();
            node1->setNextAddr(node2->getNextAddress());
            node2->setNextAddr(temp);
            head = node1;
            cout << "Successfully swapped" << endl;
            return;
        } // means node2 is head

        Node *temp = node1->getNextAddress();
        node1->setNextAddr(node2->getNextAddress());
        prev2->setNextAddr(node1);
        prev1->setNextAddr(node2);
        node2->setNextAddr(temp);
        temp = NULL;
    }

    void swapByLocation(int loc1, int loc2)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        } // if head is null

        if (loc1 == loc2)
        {
            cout << "Locations cannot be same" << endl;
            return;
        } // if locations are same

        if (loc2 < loc1)
            swap(loc1, loc2);

        Node *prev1 = NULL;
        Node *prev2 = NULL;
        Node *node1 = head;
        Node *node2 = head;

        for (int i = 0; i < loc1 - 1 && node1 != NULL; i++)
        {
            prev1 = node1;
            node1 = node1->getNextAddress();
        } // for loop

        for (int i = 0; i < loc2 - 1 && node2 != NULL; i++)
        {
            prev2 = node2;
            node2 = node2->getNextAddress();
        } // for loop

        if (node1 == NULL || node2 == NULL)
        {
            cout << "Location doesn't exist" << endl;
            return;
        } // if

        // Corrected logic for swapByLocation
        if (prev1 == NULL) // Case: Swapping Head with something else
        {
            head = node2;

            // Special check: Are they adjacent? (Swapping 1 and 2)
            if (node1->getNextAddress() == node2)
            {
                node1->setNextAddr(node2->getNextAddress());
                node2->setNextAddr(node1);
            }
            else
            { // Not adjacent (e.g., Swapping 1 and 5)
                Node *temp = node2->getNextAddress();
                node2->setNextAddr(node1->getNextAddress());
                node1->setNextAddr(temp);
                prev2->setNextAddr(node1); // Safe to use prev2 here
            }
            return;
        }

        if (node1->getNextAddress() == node2)
        {
            node1->setNextAddr(node2->getNextAddress());
            node2->setNextAddr(node1);
            prev1->setNextAddr(node2);
            cout << "Successfully swapped" << endl;
            return;
        } // if

        Node *temp = node1->getNextAddress();

        node1->setNextAddr(node2->getNextAddress());
        prev2->setNextAddr(node1);
        prev1->setNextAddr(node2);
        node2->setNextAddr(temp);
        cout << "Swapped successfully" << endl;

    } // function swapByLocation

    // concatp

    void concatLists(SLL &obj)
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

        current->setNextAddr(obj.head);
    }

    // Add this inside public section of SLL class
    ~SLL()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->getNextAddress();
            delete temp;
        }
    }

}; // SLL

int main()
{

    return 0;
}