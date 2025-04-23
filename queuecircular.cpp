#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* nums;    // Array to hold the queue elements
    int front;    // Index of the front element
    int rear;     // Index of the next element to be added
    int size;     // Maximum size of the queue
    int count;    // Current number of elements in the queue

public:
    CircularQueue(int s) {
        size = s;
        nums = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    ~CircularQueue() {
        delete[] nums; // Free allocated memory
    }

    bool isFull() {
        return count == size; // Check if the queue is full
    }

    bool isEmpty() {
        return count == 0; // Check if the queue is empty
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "The queue is full!" << endl;
            return;
        }
        nums[rear] = value; // Add element
        rear = (rear + 1) % size; // Wrap around if needed
        count++; // Increment the count of elements
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << nums[front] << endl; // Remove element
        front = (front + 1) % size; // Wrap around if needed
        count--; // Decrement the count of elements
    }

    void display() {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << nums[(front + i) % size] << " "; // Wrap around for display
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue q(size); // Create a circular queue of specified size

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
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This should indicate the queue is full
    q.display();

    return 0;
}