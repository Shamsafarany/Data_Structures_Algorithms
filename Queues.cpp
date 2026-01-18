#include <iostream>
using namespace std;

const int max_size = 100;
class Queue{
    private: 
        int front;
        int rear;
        int count;
        int data[max_size];
    public:
        Queue(){
            front = -1;
            rear = -1;
            count= 0;
        }
        bool isEmpty(){
            return (rear == -1 && front == -1);
        }
        bool isFull(){
            return ((front == 0 && rear == max_size-1) || (front - rear == 1));
        }
       
        void enqueue(int item){
            if(isFull()){
                cout <<"Queue is full!" << endl;
            } else if (isEmpty()) {
                rear++;
                front++;
                data[rear] = item;
                count++;
            } else if (rear== max_size-1) {
                rear = 0;
                data[rear] = item;
                count++;
            } else {
                rear++;
                data[rear] = item;
                count++;
            }
        }

        int dequeue(){
            if(isEmpty()) {
                return 0;
            } else if (front == rear) {
                int value= data[front];
                front = -1;
                rear = -1;
                count--;
                return value;
            } else if (front == max_size-1) {
                int value= data[front];
                front = 0;
                count--;
                return value;
            } else {
                int value= data[front];
                front++;
                count--;
                return value;
            }
        }
        int Count(){
            return count;
        }

        void display(){
            for(int i = front; i<= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        int peak(){
            return data[front];
        }
};



int main(){

    Queue q1;
    cout << q1.isEmpty() << endl;
    cout << q1.isFull() << endl;
    q1.enqueue(10);
    cout << q1.isEmpty() << endl;
    q1.enqueue(11);
    q1.enqueue(20);
    q1.display();
    cout << q1.peak() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.Count() << endl;
    q1.display();
    cout << q1.peak() << endl;

    return 0;
}