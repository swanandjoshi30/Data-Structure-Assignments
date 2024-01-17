/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not.
*/

#include <iostream>
#include <cstring> // Added for strlen
using namespace std;

#define size 10

class StackExpression {
    int top;
    char stack[size];

public:
    StackExpression() {
        top = -1;
    }

    void push(char);
    char pop();
    int isFull();
    int isEmpty();
};

void StackExpression::push(char x) {
    if (top < size - 1) {
        top++;
        stack[top] = x;
    } else {
        cout << "Stack Overflow: Unable to push " << x << ". Stack is full." << endl;
    }
}

char StackExpression::pop() {
    if (top >= 0) {
        char s = stack[top];
        top--;
        return s;
    } else {
        cout << "Stack Underflow: Unable to pop. Stack is empty." << endl;
        return '\0'; // Return null character for simplicity
    }
}

int StackExpression::isFull() {
    return (top == size - 1);
}

int StackExpression::isEmpty() {
    return (top == -1);
}

int main() {
    char exp[20], ch;
    int i = 0;

    while (true) {
        StackExpression s1;

        cout << "\n\tParenthesis Checker\n";
        cout << "-------------------------------------\n";

        cout << "Enter the expression to check for well-formed parentheses (type 'exit' to quit): ";
        cin >> exp;

        // Check if the user wants to exit
        if (strcmp(exp, "exit") == 0) {
            cout << "Exiting program.\n";
            break;
        }

        // Check if the expression starts with a closing parenthesis, square bracket, or curly brace
        if (exp[0] == ')' || exp[0] == ']' || exp[0] == '}') {
            cout << "\nInvalid Expression: Expression starts with a closing delimiter.\n";
        } else {
            while (exp[i] != '\0') {
                ch = exp[i];
                switch (ch) {
                    case '(': s1.push(ch); break;
                    case '[': s1.push(ch); break;
                    case '{': s1.push(ch); break;
                    case ')': s1.pop(); break;
                    case ']': s1.pop(); break;
                    case '}': s1.pop(); break;
                }
                i++;
            }
        }

        if (s1.isEmpty()) {
            cout << "\nExpression is well parenthesized.\n";
        } else {
            cout << "\nInvalid Expression: Not well parenthesized.\n";
        }
    }

    return 0;
}
