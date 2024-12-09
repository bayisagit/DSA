#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
private:
    char arr[MAX];
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

    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
};

bool isPalindrome(const string& str) {
    Stack stack;

    // Push all characters of the string onto the stack
    for (char ch : str) {
        stack.push(ch);
    }

    // Check if the string is a palindrome
    for (char ch : str) {
        if (ch != stack.pop()) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    // Remove spaces and convert to lower case for palindrome check
    string filteredInput;
    for (char ch : input) {
        if (!isspace(ch)) {
            filteredInput += tolower(ch);
        }
    }

    if (isPalindrome(filteredInput)) {
        cout << "\"" << filteredInput << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << filteredInput << "\" is not a palindrome." << endl;
    }

    return 0;
}
