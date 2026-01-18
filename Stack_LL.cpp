#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* Next;
};

class Stack{
    private:
    Node* head;
    int size;
    int capacity;
    public:
    Stack(){
        head = NULL;
        size = 0;
        capacity = 100;
    }
    void push (int value) {
        if(size < capacity) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->Next = head;
            head = newNode;
            size++;
        } else {
            cout <<"Stack is full!" << endl;
        }
    }
    void pop(){
        if(size == 0) {
            cout <<"Stack is empty!" << endl;
        } else {
            Node* temp = head;
            head = temp->Next;
            delete temp;
            size--;
        }
    }

    void display(){
        Node* temp = head;
        while(temp!= NULL) {
            cout << temp -> data << endl;
            temp = temp->Next;
        }
    }

    int top(){
        if (size != 0) {
            Node* temp = head;
            return temp->data;
        } else {
            return 0;
        }
    }

    bool isEmpty(){
        return size == 0;
    }
};

int main(){

    Stack s1;
    s1.push(10);
    s1.push(9);
    s1.push(8);

    s1.display();
    s1.pop();
    s1.display();

    cout << s1.top() << endl;
    cout << s1.isEmpty() << endl;


    return 0;
}