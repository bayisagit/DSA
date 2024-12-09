#include <iostream>
using namespace std;

// Singly Linked List
class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node{value, nullptr};
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (!head) return;
        if (position == 0) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) return;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    ~SinglyLinkedList() {
        while (head) {
            deleteAtBeginning();
        }
    }
};

// Circular Singly Linked List
class CircularSinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteAtBeginning() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    ~CircularSinglyLinkedList() {
        while (head) {
            deleteAtBeginning();
        }
    }
};

//double linked list!
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head, nullptr};
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node{value, nullptr, nullptr};
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int position) {
        if (!head) return;
        if (position == 0) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (!temp) return;
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void displayBackward() {
        Node* temp = head;
        if (!temp) return;
        while (temp->next) {
            temp = temp->next;
        }
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            deleteAtBeginning();
        }
    }
};

// Circular Doubly Linked List
class CircularDoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head->prev;
        tail->next = head->next;
        head->next->prev = tail;
        delete head;
        head = tail->next;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        delete tail;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    ~CircularDoublyLinkedList() {
        while (head) {
            deleteAtBeginning();
        }
    }
};

int main() {
    SinglyLinkedList sList;
    CircularSinglyLinkedList csList;
    DoublyLinkedList dList;
    CircularDoublyLinkedList cdList;

    // Sample data insertion for demonstration
    sList.insertAtEnd(1);
    sList.insertAtEnd(2);
    sList.insertAtEnd(3);
    csList.insertAtEnd(1);
    csList.insertAtEnd(2);
    csList.insertAtEnd(3);
    dList.insertAtEnd(1);
    dList.insertAtEnd(2);
    dList.insertAtEnd(3);
    cdList.insertAtEnd(1);
    cdList.insertAtEnd(2);
    cdList.insertAtEnd(3);

    while (true) {
        cout << "Choose an option:\n";
        cout << "1 for Singly Linked List\n";
        cout << "2 for Circular Singly Linked List\n";
        cout << "3 for Doubly Linked List\n";
        cout << "4 for Circular Doubly Linked List\n";
        cout << "5 for Exit\n";
        int ch;
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "You chose the Singly Linked List.\n";
            cout << "1: Insert at beginning\n2: Insert at end\n3: Insert at position\n4: Delete at beginning\n5: Delete at position\n6: Delete at end\n7: Display\n";
            int operation;
            cin >> operation;
            if (operation == 1) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                sList.insertAtBeginning(value);
            } else if (operation == 2) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                sList.insertAtEnd(value);
            } else if (operation == 3) {
                int value, position;
                cout << "Enter value to insert and position: ";
                cin >> value >> position;
                sList.insertAtPosition(value, position);
            } else if (operation == 4) {
                sList.deleteAtBeginning();
            } else if (operation == 5) {
                int position;
                cout << "Enter position to delete: ";
                cin >> position;
                sList.deleteAtPosition(position);
            } else if (operation == 6) {
                sList.deleteAtEnd();
            } else if (operation == 7) {
                cout << "Singly Linked List: ";
                sList.display();
            }
        } else if (ch == 2) {
            cout << "You chose the Circular Singly Linked List.\n";
            cout << "1: Insert at beginning\n2: Insert at end\n3: Delete at beginning\n4: Delete at end\n5: Display\n";
            int operation;
            cin >> operation;
            if (operation == 1) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                csList.insertAtBeginning(value);
            } else if (operation == 2) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                csList.insertAtEnd(value);
            } else if (operation == 3) {
                csList.deleteAtBeginning();
            } else if (operation == 4) {
                csList.deleteAtEnd();
            } else if (operation == 5) {
                cout << "Circular Singly Linked List: ";
                csList.display();
            }
        } else if (ch == 3) {
            cout << "You chose the Doubly Linked List.\n";
            cout << "1: Insert at beginning\n2: Insert at end\n3: Insert at position\n4: Delete at beginning\n5: Delete at position\n6: Delete at end\n7: Display Forward\n8: Display Backward\n";
            int operation;
            cin >> operation;
            if (operation == 1) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                dList.insertAtBeginning(value);
            } else if (operation == 2) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                dList.insertAtEnd(value);
            } else if (operation == 3) {
                int value, position;
                cout << "Enter value to insert and position: ";
                cin >> value >> position;
                dList.insertAtPosition(value, position);
            } else if (operation == 4) {
                dList.deleteAtBeginning();
            } else if (operation == 5) {
                int position;
                cout << "Enter position to delete: ";
                cin >> position;
                dList.deleteAtPosition(position);
            } else if (operation == 6) {
                dList.deleteAtEnd();
            } else if (operation == 7) {
                cout << "Doubly Linked List Forward: ";
                dList.displayForward();
            } else if (operation == 8) {
                cout << "Doubly Linked List Backward: ";
                dList.displayBackward();
            }
        } else if (ch == 4) {
            cout << "You chose the Circular Doubly Linked List.\n";
            cout << "1: Insert at beginning\n2: Insert at end\n3: Delete at beginning\n4: Delete at end\n5: Display\n";
            int operation;
            cin >> operation;
            if (operation == 1) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                cdList.insertAtBeginning(value);
            } else if (operation == 2) {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                cdList.insertAtEnd(value);
            } else if (operation == 3) {
                cdList.deleteAtBeginning();
            } else if (operation == 4) {
                cdList.deleteAtEnd();
            } else if (operation == 5) {
                cout << "Circular Doubly Linked List: ";
                cdList.display();
            }
        } else if (ch == 5) {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
