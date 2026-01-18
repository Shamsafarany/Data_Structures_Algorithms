#include <iostream>
using namespace std;

class Node{
    public:
        int priority;
        int data;
        Node *Next;
};

class P_Queue{
    private:
        Node* front;
    public:
        P_Queue(){
            front = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }

        bool enqueue(int item, int priority){
            Node* newNode = new Node;
            newNode-> data = item;
            newNode-> priority = priority;

            //insert as first element
            if (isEmpty() || priority >= front->priority) {
                newNode -> Next = front;
                front = newNode;
            } else {
                Node* temp = front;
                while (temp->Next != NULL && temp->Next->priority > priority) {
                    temp = temp -> Next;
                }
                newNode -> Next = temp -> Next;
                temp->Next = newNode;
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






    return 0;
}