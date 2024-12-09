#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int a[MAX];

public:
    Stack() { top = -1; }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    } else {
        return a[top--];
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty\n";
        return 0;
    } else {
        return a[top];
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " popped from stack\n";
    cout << "Top element is: " << s.peek() << endl;

    cout << "Elements present in stack: ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
