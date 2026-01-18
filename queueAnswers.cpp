#include <iostream> // Including necessary library for input and output operations

using namespace std;

const int MAX_SIZE = 100; // Maximum size for the queue

class Queue {
private:
    int front; // Front of the queue
    int rear; // Rear of the queue
    int arr[MAX_SIZE]; // Array to store queue elements

public:
    Queue() {
        front = -1; // Initializing front index to -1
        rear = -1; // Initializing rear index to -1
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1); // Check if the queue is full
    }

    bool isEmpty() {
        return (front == -1 && rear == -1); // Check if the queue is empty
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full" << endl; // Display error if the queue is full
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x; // Add an element to the rear of the queue
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error if the queue is empty
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error if the queue is empty
            return -1;
        }
        return arr[front]; // Return the element at the front of the queue
    }

    void display() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error if the queue is empty
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " "; // Display all elements in the queue
        }
        cout << endl;
    }  

    // Function to copy elements from q1 to q2
    void copy_Queue(Queue& q1, Queue& q2) {
        if (q1.isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error if q1 is empty
            return;
        }
        for (int i = q1.front; i <= q1.rear; i++) {
            q2.enqueue(q1.arr[i]); // Copy elements from q1 to q2
        }
    }
};

int main() {
    cout << "Initialize a Queue." << endl;
    Queue q1, q2, q3; // Creating instances of Queue
    cout << "\nInsert some elements into the queue:" << endl;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout << "Queue-1" << endl;
    q1.display(); // Display elements of queue 1
    cout << "Is q2 is blank? " << q2.isEmpty() << endl; // Check if q2 is empty
    cout << "Is q3 is blank? " << q3.isEmpty() << endl; // Check if q3 is empty
    cout << "\nCopy the elements of q1 to q2:" << endl;
    q1.copy_Queue(q1, q2); // Copy elements from q1 to q2
    cout << "Queue-2" << endl;
    q2.display(); // Display elements of queue 2
    cout << "\nCopy the elements of q3 to q1:" << endl;
    q1.copy_Queue(q3, q1); // Copy elements from q3 to q1
system ("pause");
    return 0;
}
