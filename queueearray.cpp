#include <iostream>
using namespace std;

class Queue {
private:
    int* nums;    // Array to hold the queue elements
    int front;    // Index of the front element
    int rear;     // Index of the next element to be added
    int size;     // Maximum size of the queue

public:
    Queue(int s) {
        size = s;
        nums = new int[size];
        front = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] nums; // Free allocated memory
    }

    void enqueue(int value) {
        if (rear >= size) {
            cout << "The queue is full!" << endl;
            return;
        }
        nums[rear++] = value; // Add element and increment rear
    }

    void dequeue() {
        if (front == rear) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << nums[front++] << endl; // Remove element and increment front
    }

    void display() {
        if (front == rear) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i < rear; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size); // Create a queue of specified size

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    // Display the queue
    q.display();

    // Dequeue an element
    q.dequeue();
    
    // Display the queue again
    q.display();

    // Attempt to enqueue beyond the queue size    
    // Final display
    q.display();

    return 0;
}