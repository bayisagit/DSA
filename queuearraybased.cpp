#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;

    Queue(int c) : front(0), rear(-1), capacity(c) {
        queue = new int[c];
    }

    ~Queue() { delete[] queue; }

    void enqueue(int data) {
        if (rear == capacity - 1) {
            cout << "\nQueue is full\n";
            return;
        }
        queue[++rear] = data;
    }

    void dequeue() {
        if (front > rear) {
            cout << "\nQueue is empty\n";
            return;
        }
        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    }

    void display() {
        if (front > rear) {
            cout << "\nQueue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << " " << queue[i] << " <-- ";
        }
        cout << "\n";
    }

    void frontElement() {
        if (rear == -1) {
            cout << "\nQueue is Empty\n";
            return;
        }
        cout << "\nFront Element is: " << queue[front] << "\n";
    }
};

int main() {
    Queue q(4);
    q.display();

    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.enqueue(60);
    q.display();

    q.dequeue();
    q.dequeue();
    cout << "\nAfter two deletions:\n";
    q.display();

    cout << "\nAfter one insertion:\n";
    q.enqueue(60);
    q.display();
    q.frontElement();

    return 0;
}