#include<iostream>
using namespace std;

#define SIZE 5

class Dequeue {
    int arr[SIZE], front, rear, count;

public:
    Dequeue();
    void addToFront(int);
    void addToRear(int);
    void deleteFromFront();
    void deleteFromRear();
    void display();
};

Dequeue::Dequeue() {
    front = -1;
    rear = -1;
    count = 0;
}

void Dequeue::addToFront(int item) {
    if (front == -1) {
        front++;
        rear++;
        arr[rear] = item;
        count++;
    } else if (rear >= SIZE - 1) {
        cout << "\nInsertion is not possible, overflow!!!!";
    } else {
        for (int i = rear + 1; i > front; i--) {
            arr[i] = arr[i - 1];
        }
        arr[front] = item;
        count++;
        rear++;
    }
}

void Dequeue::addToRear(int item) {
    if (front == -1) {
        front++;
        rear++;
        arr[rear] = item;
        count++;
    } else if (rear >= SIZE - 1) {
        cout << "\nInsertion is not possible, overflow!!!";
    } else {
        arr[++rear] = item;
        count++;
    }
}

void Dequeue::display() {
    if (front == -1) {
        cout << "Dequeue is empty";
    } else {
        cout << "Dequeue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void Dequeue::deleteFromRear() {
    if (front == -1) {
        cout << "Deletion is not possible: Dequeue is empty";
    } else {
        cout << "The deleted element is " << arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = rear - 1;
        }
    }
}

void Dequeue::deleteFromFront() {
    if (front == -1) {
        cout << "Deletion is not possible: Dequeue is empty";
    } else {
        cout << "The deleted element is " << arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
    }
}

int main() {
    int choice, item;
    Dequeue dq;

    do {
        cout << "\n\n****DEQUEUE OPERATION****\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Display\n";
        cout << "4. Delete from the front\n";
        cout << "5. Delete from the rear\n";
        cout << "6. Exit\n";
        cout << "Enter your choice <1-6>: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> item;
            dq.addToFront(item);
            break;
        case 2:
            cout << "Enter the element to be inserted: ";
            cin >> item;
            dq.addToRear(item);
            break;
        case 3:
            dq.display();
            break;
        case 4:
            dq.deleteFromFront();
            break;
        case 5:
            dq.deleteFromRear();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 6);

    return 0;
}

