#include <iostream>
#include <string>

using namespace std;

class Node
{
    int data;
    Node* nextAddr;

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

    Node(Node* addr)
    {
        data = 0;
        nextAddr = addr;
    }

    Node(int d, Node* addr)
    {
        data = d;
        nextAddr = addr;
    }

    int getData() { return data; }
    Node* getNextAddress() { return nextAddr; }

    void setData(int d) { data = d; }
    void setNextAddr(Node* addr) { nextAddr = addr; }
};

class CSLL // Renamed to Circular Singly Linked List
{

    Node* head;
    Node* current;
    int nov; // Number of values

public:
    CSLL()
    {
        head = NULL;
        current = NULL;
        nov = 0;
    }

    // Destructor to prevent memory leaks
    ~CSLL() {
        if (head == NULL) return;

        Node* temp = head;
        Node* nextNode;

        // Break the circle for deletion
        do {
            nextNode = temp->getNextAddress();
            delete temp;
            temp = nextNode;
        } while (temp != head);
        
        head = NULL;
    }

    Node* getHead() { return head; }

    // Helper to find the last node (Tail)
    Node* getTail() {
        if (head == NULL) return NULL;
        Node* temp = head;
        while (temp->getNextAddress() != head) {
            temp = temp->getNextAddress();
        }
        return temp;
    }

    // --- Insert Section ---

    void insertAtStart(int val)
    {
        Node* newNode = new Node(val);
        
        if (head == NULL)
        {
            head = newNode;
            newNode->setNextAddr(head); // Points to itself
        }
        else
        {
            Node* tail = getTail();
            newNode->setNextAddr(head);
            tail->setNextAddr(newNode); // Update tail to point to new head
            head = newNode;
        }
        nov++;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->setNextAddr(head); // Points to itself
        }
        else
        {
            Node* tail = getTail();
            tail->setNextAddr(newNode);
            newNode->setNextAddr(head); // New last node points back to head
        }
        nov++; // Fixed: Added increment
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
        // Circular Safety: Check if we wrapped around
        for (int i = 1; i < loc - 1; i++)
        {
            current = current->getNextAddress();
            if (current == head) { // Prevent infinite loop if loc is huge
                cout << "Invalid position" << endl;
                return;
            }
        }

        Node* newNode = new Node(val, current->getNextAddress());
        current->setNextAddr(newNode);
        nov++;
    }

    // --- Delete Section ---

    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->getNextAddress() == head) // Only 1 node
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node* tail = getTail();
            Node* temp = head;
            
            head = head->getNextAddress();
            tail->setNextAddr(head); // Tail points to new head
            
            delete temp;
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

        if (head->getNextAddress() == head) // Only 1 node
        {
            delete head;
            head = NULL;
        }
        else
        {
            current = head;
            // Stop at the node BEFORE the last node
            while (current->getNextAddress()->getNextAddress() != head)
            {
                current = current->getNextAddress();
            }

            Node* temp = current->getNextAddress(); // This is the tail
            current->setNextAddr(head); // Current becomes new tail, points to head
            delete temp;
        }
        nov--;
    }

    void deleteAtSpecificLocation(int loc)
    {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (loc <= 0) {
            cout << "\tInvalid position" << endl;
            return;
        }

        if (loc == 1) {
            deleteAtStart();
            return;
        }

        current = head;
        for (int i = 1; i < loc - 1; i++) {
            current = current->getNextAddress();
            if (current->getNextAddress() == head) { // Limit check
                cout << "\tThis location doesn't exist" << endl;
                return;
            }
        }

        Node* temp = current->getNextAddress();
        if (temp == head) { // User tried to delete beyond the list
             cout << "\tThis location doesn't exist" << endl;
             return;
        }

        current->setNextAddr(temp->getNextAddress());
        delete temp;
        nov--;
    }

    // --- Display Section ---

    void displayData()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        
        current = head;
        do {
            cout << "Val: " << current->getData() << endl;
            current = current->getNextAddress();
        } while (current != head); // Stop when we get back to start
    }

    void displayInReverseOrder()
    {
        // Recursion is safer/easier for printing reverse in Circular than modifying list
        if (head == NULL) return;
        displayHelperReverse(head);
    }
    
    // Recursive helper that knows when to stop
    void displayHelperReverse(Node* n) {
        if (n->getNextAddress() != head) {
            displayHelperReverse(n->getNextAddress());
        }
        cout << "Val: " << n->getData() << endl;
    }


    void displayOnlyEven()
    {
        if (head == NULL) return;
        current = head;
        do {
            if (current->getData() % 2 == 0) {
                cout << "Val: " << current->getData() << endl;
            }
            current = current->getNextAddress();
        } while (current != head);
    }

    void displayOnlyOdd()
    {
        if (head == NULL) return;
        current = head;
        do {
            if (current->getData() % 2 != 0) {
                cout << "Val: " << current->getData() << endl;
            }
            current = current->getNextAddress();
        } while (current != head);
    }

    // --- Search Section ---

    void searchByValue(int val)
    {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        bool found = false;
        current = head;
        do {
            if (current->getData() == val)
            {
                found = true;
                break;
            }
            current = current->getNextAddress();
        } while (current != head);

        if (found) cout << "The number is present in the list" << endl;
        else cout << "The number is not present in the list" << endl;
    }

    void countValue(int val)
    {
        int count = 0;
        if (head == NULL) return;

        current = head;
        do {
            if (current->getData() == val) count++;
            current = current->getNextAddress();
        } while (current != head);

        cout << "There are " << count << " matching numbers in the list" << endl;
    }

    void countValueAndLocation(int val)
    {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }

        // We can use a simplified local list or just print to avoid complexity
        // adapting SLL logic here directly:
        int count = 0;
        int location = 1;
        current = head;

        cout << "Locations for value " << val << ": ";
        
        do {
            if (current->getData() == val) {
                count++;
                cout << location << " ";
            }
            location++;
            current = current->getNextAddress();
        } while(current != head);

        cout << endl << "Total Count: " << count << endl;
    }

    // --- Swap Section ---
    // Swapping in Circular Lists is complex because Head has a "Previous" (The Tail)
    
    void swapByLocation(int loc1, int loc2)
    {
        if (head == NULL || loc1 == loc2) return;
        if (loc2 < loc1) swap(loc1, loc2);

        Node* prev1 = NULL; 
        Node* prev2 = NULL;
        Node* node1 = head;
        Node* node2 = head;

        // In Circular, finding previous of head is getting the tail
        if (loc1 == 1) prev1 = getTail(); 

        // Navigate to nodes
        // Note: Logic adjusted for Circular traversal
        for (int i = 1; i < loc1; i++) {
            prev1 = node1;
            node1 = node1->getNextAddress();
        }
        for (int i = 1; i < loc2; i++) {
            prev2 = node2;
            node2 = node2->getNextAddress();
        }

        if (node1 == head && loc1 != 1) { // Wrapped around unintentionally
            cout << "Invalid location" << endl; return;
        }

        // Standard Swap Pointers Logic
        if (prev1 != NULL) prev1->setNextAddr(node2);
        if (prev2 != NULL) prev2->setNextAddr(node1);

        Node* temp = node1->getNextAddress();
        node1->setNextAddr(node2->getNextAddress());
        node2->setNextAddr(temp);

        // Fix Head pointer if needed
        if (loc1 == 1) head = node2;
        
        cout << "Swapped successfully" << endl;
    }

    // Helper for concat
    void concatLists(CSLL& obj)
    {
        if (head == NULL) {
            head = obj.head; // Basic copy
            return;
        }
        if (obj.head == NULL) return;

        Node* tail1 = getTail();
        Node* tail2 = obj.getTail();

        tail1->setNextAddr(obj.head); // Tail 1 points to Head 2
        tail2->setNextAddr(head);     // Tail 2 points to Head 1 (Completing the big circle)
    }

};

int main()
{
    CSLL list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtStart(5);

    cout << "Circular List: " << endl;
    list.displayData();

    cout << "Deleting start..." << endl;
    list.deleteAtStart();
    list.displayData();

    return 0;
}