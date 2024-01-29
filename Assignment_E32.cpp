#include<iostream>
#include<cstdlib>

using namespace std;

class Pizza {
    int rear, front, orders[5];

public:
    Pizza() {
        front = -1;
        rear = -1;
    }

    int isEmpty() {
        return (front == -1 && rear == -1);
    }

    int isFull() {
        return (front == -1 && rear == 4);
    }

    void add() {
        if (!isFull()) {
            cout << "Enter order id: ";
            if (front == -1 && rear == -1) {
                front = 0;
                rear = 0;
                cin >> orders[rear];
            } else {
                rear = (rear + 1) % 5;
                cin >> orders[rear];
            }
            char c;
            cout << "Do you want to add another order? ";
            cin >> c;
            if (c == 'y' || c == 'Y')
                add();
        } else {
            cout << "Orders are full!!!";
        }
    }

    void serve() {
        if (!isEmpty()) {
            if (front == rear) {
                cout << "Order served is: " << orders[front];
                front = -1;
                rear = -1;
            } else {
                cout << "Order served is: " << orders[front];
                front = (front + 1) % 5;
            }
        } else {
            cout << "Orders are empty!!!";
        }
    }

    void display() {
        if (!isEmpty()) {
            cout << "Orders in queue: ";
            for (int i = front; i != rear; i = (i + 1) % 5) {
                cout << orders[i] << " <- ";
            }
            cout << orders[rear];
        } else {
            cout << "Orders are empty!!!";
        }
    }

    void check() {
        int choice;
        cout << "\n\n * * * * PIZZA PARLOUR * * * * \n";
        cout << "\n 1. Add a Pizza \n 2. Display the Orders \n 3. Serve a pizza \n 4. Exit \n Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                serve();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice ";
                check();
        }

        char ch1;
        cout << "\n Do you want to continue? ";
        cin >> ch1;
        if (ch1 == 'y' || ch1 == 'Y')
            check();
    }
};

int main() {
    Pizza p1;
    p1.check();
    return 0;
}

