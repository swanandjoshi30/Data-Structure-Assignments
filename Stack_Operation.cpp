#include<iostream>
using namespace std;
#define MAX 5

class stack_operation
{
private:
    int top;
    int s[MAX];

public:
    stack_operation()
    {
        top = -1;
    }

    int isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty !" << endl;
            return 1;
        }
        else
        {
            cout << "Stack is not empty !" << endl;
            return 0;
        }
    }

    int isFull()
    {
        if (top == MAX - 1)
        {
            cout << "Overflow";
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push()
    {
        if (isFull() == 1)
        {
            cout << "Overflow";
        }
        else
        {
            top++;
            cout << "Enter value: ";
            cin >> s[top];
            cout << "Pushed" << endl;
        }
    }

    void pop()
    {
        if (isEmpty() == 1)
        {
            cout << "Stack empty";
        }
        else
        {
            cout << s[top] << " is popped" << endl;
            top--;
        }
    }

    void display()
    {
        if (isEmpty() == 1)
        {
            cout << "Stack empty, nothing to display" << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++)
            {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    stack_operation s;
    int ch;

    do
    {
        cout << "Enter your choice : " << endl;
        cout << " 1. Insert element : " << endl;
        cout << " 2. Delete element : " << endl;
        cout << " 3. Display stack : " << endl; // Added choice
        cout << " 4. Quit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display(); // Added case
            break;
        case 4:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 4);

    return 0;
}
