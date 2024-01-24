#include <iostream>
using namespace std;

#define size 10

class StackExp {
    int top;
    char stack[size];

public:
    StackExp() {
        top = -1;
    }

    void push(char);
    char pop();
    int isFull();
    int isEmpty();
};

void StackExp::push(char x) {
    top = top + 1;
    stack[top] = x;
}

char StackExp::pop() {
    char s;
    s = stack[top];
    top = top - 1;
    return s;
}

int StackExp::isFull() {
    return (top == size - 1) ? 1 : 0;
}

int StackExp::isEmpty() {
    return (top == -1) ? 1 : 0;
}

int main() {
    StackExp s1;
    char exp[20], ch;
    int i = 0;

    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "\nEnter the expression to check whether it is well-formed or not: ";
    cin >> exp;

    // Check for starting delimiter
    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')) {
        cout << "\nInvalid Expression.....\n";
        return 0;
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
            i = i + 1;
        }
    }

    if (s1.isEmpty()) {
        cout << "\nExpression is well parenthesized...\n";
    } else {
        cout << "\nSorry !!! Invalid Expression or not well parenthesized....\n";
    }

    return 0;
}


