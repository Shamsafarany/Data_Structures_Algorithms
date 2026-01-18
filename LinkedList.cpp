#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* Next;
};

class LinkedList{
    private:
        Node* head;
    public:

        //construtor-> initialize empty list
        LinkedList(){
            head = NULL;
        }
        bool isEmpty(){
            return head == NULL;
        }

        void insertNode(int index, int data){
            //check condition
            if (index < 0 || (index > 0 && head ==NULL)) {
                cout <<"Insertion failed!" << endl;
                return;
            }

            //create new node (dynamic)
            Node* newNode = new Node();
            newNode -> data = data;

            //insert at head as first element
            if (index == 0) {
                newNode -> Next = head;
                head = newNode;
                cout <<"Inserted at first position!" << endl;
            } else {
                //insert between two nodes
                int currentIndex = 0;
                Node* temp = head;
                while (temp->Next !=NULL && currentIndex < index) {
                    temp = temp ->Next; //move to next node
                    currentIndex++;
                }
                //reached location
                newNode -> Next = temp -> Next;
                temp ->Next = newNode;
                cout <<"Inserted at index " << index << endl; 
            }

        }

        int findNode(int x){
            Node* temp = head;
            int currentIndex = 0;
            while(temp!= NULL && temp->data != x){
                temp = temp -> Next;
                currentIndex++;
            }
            //found or not found
            if (temp!= NULL) {
                cout <<"Element found!" << endl;
                return currentIndex;
            } else {
                cout <<"Element not found!" << endl;
                return -1;
            }
        }

        void displayList(){
            Node* temp = head;
            int count = 0;
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp-> Next;
                count++;
            }
            cout << endl;
            cout <<"Number of elements: "<< count << endl;
        }

        int deleteNode(int x) {
            Node* temp = head;
            Node* prev = NULL;
            int currentIndex = 0;

            while (temp != NULL && temp->data != x) {
                prev = temp;
                temp = temp->Next;
                currentIndex++;
            }
            //found
            if (temp) {
                if (prev) {
                    prev -> Next = temp ->Next;
                    delete temp;
                } else {
                    head = temp->Next;
                    delete temp;
                }
                return currentIndex;
            } else {
                return -1;
            }

        }

        void displayLastElement(){
            Node* temp = head;
            
            while(temp->Next != NULL){
                temp = temp ->Next;
            }
            cout << temp->data << endl;
        
        }

        void displayMidElement(){
            Node* temp1 = head;
            int count = 0;
            while(temp1 != NULL) {
                count++;
                temp1 = temp1 ->Next;
            }

            int mid = count / 2;
            int currentIndex = 0;
            Node* temp2 = head;
            while(currentIndex< mid) {
                temp2 = temp2 -> Next;
                currentIndex++;
            }
            cout <<"Mid Element: " << temp2->data << endl;

        }

        void getElement(int index) {
            Node* temp = head;
            int currentIndex = 0;
            while(temp!= NULL && currentIndex < index) {
                temp = temp ->Next;
                currentIndex++;
            }
            if (temp){
                cout <<"Element at index " << index << ": " << temp->data << endl;
            } else {
                cout <<"Out of bounds!" << endl;
            }
            
         }

         void deleteFirstElement(){
            Node* temp = head;
            
            if (head!= NULL) {
                head = head->Next;
                delete temp;
            }
            displayList();
         }

         void deleteLastElement(){
            Node* temp = head;
            Node* prev= NULL;
            int currentIndex = 0;
            while(temp->Next != NULL) {
                prev = temp;
                temp = temp->Next;
            }
            if (prev) {
                prev->Next = NULL;
                delete temp;
            } else {
                head = head->Next;
                delete temp;
            }
            
            displayList();
         }

};


int main(){

    LinkedList l1;
    l1.insertNode(0, 10);
    l1.insertNode(0, 20);
    l1.insertNode(0, 30);
    l1.insertNode(0, 40);
    l1.insertNode(0, 50);

    l1.displayList();
    l1.displayLastElement();
    l1.displayMidElement();
    l1.getElement(3);
    l1.getElement(7);
    l1.deleteFirstElement();
    l1.deleteFirstElement();
    l1.deleteLastElement();
    l1.deleteLastElement();
    l1.deleteLastElement();
    l1.displayList();



    return 0;
}