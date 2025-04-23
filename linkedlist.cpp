#include <iostream>
using namespace std;

class Linkedlist {
private:
    struct Node {
        int data;
        Node* next;
    };
    
    Node* head;

public:
    Linkedlist() : head(nullptr) {}

    void isert(int value) {
        Node* Newnode = new Node{value, head};
        head = Newnode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << (*current).data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void inseraf(int k, int value) {
        if (k < 1) {
            cout << "Position must be 1 or greater." << endl;
            return;
        }

        Node* nwnode = head;
        for (int i = 1; i < k - 1 && nwnode != nullptr; i++) {
            nwnode = nwnode->next;
        }

        if (nwnode == nullptr && k > 1) {
            cout << "Less than " << k << " nodes...!" << endl;
            return;
        }

        Node* newnode = new Node{value, nullptr};
        if (k == 1) {
            newnode->next = head;
            head = newnode;
        } else {
            newnode->next = nwnode->next;
            nwnode->next = newnode;
        }
    }

    ~Linkedlist() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextnode = current->next;
            delete current;
            current = nextnode;
        }
    }
};

int main() {
    Linkedlist nums;
    nums.isert(8);
    nums.isert(1);
    nums.isert(6);
    nums.isert(10);
    
    cout << "The linked list is: ";
    nums.display();

    nums.inseraf(2, 5); // Insert 5 at position 2
    cout << "After inserting 5 at position 2: ";
    nums.display();

    return 0;
}