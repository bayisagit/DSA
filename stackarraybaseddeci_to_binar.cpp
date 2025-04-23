#include <iostream>
using namespace std;

#define MAX 3

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1;
    }
};

void decimalToBinary(int decimal) {
    Stack stack;

    while (decimal > 0) {
        stack.push(decimal % 2);
        decimal /= 2;
    }

    cout << "Binary representation: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int decimal;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    decimalToBinary(decimal);

    return 0;
}
