#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) : data(new_data), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int new_data) {
        Node* new_node = new Node(new_data);
        if (isEmpty()) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr; // Update rear if queue becomes empty
        delete temp;
    }

    int getFront() {
        return isEmpty() ? INT_MIN : front->data;
    }

    int getRear() {
        return isEmpty() ? INT_MIN : rear->data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();

    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    return 0;
}