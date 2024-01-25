#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to check if a character is an operand (alphabet)
bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to check if a character is an operator (+, -, *, /)
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else if (isOperator(ch)) {
            while (!s.empty() && getPrecedence(ch) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (int i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];

        if (isOperand(ch)) {
            s.push(ch - '0'); // Convert char to integer
        } else if (isOperator(ch)) {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    string postfixRes = infixToPostfix(exp);
    cout << "Postfix expression: " << postfixRes << endl;

    int result = evaluatePostfix(postfixRes);
    cout << "Result: " << result << endl;

    return 0;
}

