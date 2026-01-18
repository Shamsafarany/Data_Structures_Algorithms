#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* Next;
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        bool enqueue(int element){
            Node* newNode = new Node;
            newNode -> data = element;
            newNode -> Next = NULL;
            if(isEmpty()) {
                front = rear = newNode;
            } else {
                rear->Next = newNode;
                rear = newNode;
                return true;
            }
        }
        bool dequeue(){
            if(isEmpty()){
                return false;
            } else {
                Node *temp = front;
                front = front->Next;
                delete temp;
                return true;
            }
        }
        void display(){
            Node* temp = front;
            while(temp != NULL) {
                cout << temp->data << endl;
                temp = temp->Next;
            }
        }
};

int main(){

    Queue q1 = Queue();
    cout << q1.isEmpty() << endl;
    cout << q1.enqueue(10) << endl;
    cout << q1.enqueue(20) << endl;
    cout << q1.enqueue(30) << endl;
    q1.display();
    cout << q1.dequeue()<< endl;
    q1.display();
   



    return 0;
}