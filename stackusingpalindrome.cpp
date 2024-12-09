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
        return '\0'; // Return null character if stack is empty
    }
};

bool isPalindrome(const std::string& str) {
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
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Remove spaces and convert to lower case for palindrome check
    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (isPalindrome(input)) {
        std::cout << "\"" << input << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << input << "\" is not a palindrome." << std::endl;
    }

    return 0;
}
