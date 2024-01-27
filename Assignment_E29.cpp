#include<iostream>
#include<cstdlib>
using namespace std;

class JobQueue {
private:
    int rear, front, q[5];

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the job queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the job queue is full
    bool isFull() {
        return front == -1 && rear == 4;
    }

    // Function to add a job to the queue
    void addJob(int job) {
        if (isFull()) {
            cout << "The job queue is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        q[rear] = job;
        cout << "Job " << job << " added to job queue" << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (isEmpty()) {
            cout << "Nothing to delete, please add some jobs first!" << endl;
            return;
        }
        cout << "Job deleted is " << q[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

    // Function to display jobs in the queue
    void displayJobs() {
        if (isEmpty()) {
            cout << "Nothing to display." << endl;
            return;
        }
        cout << "Jobs in queue are:" << endl;
        int i = front;
        while (i != rear) {
            cout << q[i] << " ";
            i = (i + 1) % 5;
        }
        cout << q[rear];
    }
};

int main() {
    JobQueue jb;
    int ch, job;
    do {
        cout << endl << "Enter your choice (1 to 4):" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter job: ";
                cin >> job;
                jb.addJob(job);
                break;
            case 2:
                jb.deleteJob();
                break;
            case 3:
                jb.displayJobs();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid option. Please re-run and choose a valid option." << endl;
        }
    } while (ch != 4);
    return 0;
}

