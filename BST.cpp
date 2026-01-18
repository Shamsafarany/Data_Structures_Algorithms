#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;   
};

class BST{
    private:
        Node *root;
    public:
        BST(){
            root = NULL;
        }

        bool isEmpty(){
            return root == NULL;
        }

        void insert(int x) {
            Node *newNode = new Node();
            Node *parent = NULL;
            newNode->data = x;
            newNode-> left = NULL;
            newNode-> right = NULL;

            if (isEmpty()){
                root = newNode;
            } else {
                Node *temp = root;         
                while(temp!= NULL) {
                    parent = temp;
                    if (newNode->data < temp->data) {
                        temp = temp -> left;
                    } else {
                        temp = temp -> right;
                    }
                }
                if (newNode->data > parent->data) {
                    parent->right = newNode;
                } else {
                    parent->left = newNode;
                }
            }
        }

        void printInOrder(Node *nd){
            if (nd != NULL) {
                printInOrder(nd -> left);
                cout << nd -> data << endl;
                printInOrder(nd -> right);
            }
        }
        void printPreOrder(Node *nd) {
            if (nd != NULL) {
                cout << nd -> data << endl;
                printPreOrder(nd -> left);
                printPreOrder(nd -> right);
            }
        }
        void printPostOrder(Node *nd) {
            if (nd != NULL) {       
                printPostOrder(nd -> left);
                printPostOrder(nd -> right);
                cout << nd -> data << endl;
            }
        }

        bool search(int x, Node *nd) {
            if (nd == NULL) {
                return false;
            } else if (nd -> data == x) {
                return true;
            } else if (x < nd -> data) {
                return search(x, nd -> left);
            } else {
                return search(x, nd -> right);
            }
        }

        //iterative approach
        bool search(int x) {
            Node* temp = root;
            while (temp!= NULL) {
                if (temp->data == x) {
                    return true;
                } else if (x < temp->data){
                    temp = temp -> left;
                } else {
                    temp = temp-> right;
                }
            }
            return false;
        }

        void remove(int x) {
            if (isEmpty()) {
                cout << "Tree is empty!" << endl;
                return;
            } 
            //need parent
            bool isFound = false;
            Node *temp = root;
            Node *parent = NULL;
            while (temp!= NULL) {
                if (temp->data == x) {
                    isFound = true;
                    break;
                } else {
                    parent = temp;
                    if (x < temp->data){
                        temp = temp-> left;
                    } else {
                        temp = temp->right;
                    }
                }
            }
            if (!isFound) {
                cout << "Not found" << endl;
                return;
            }

            //case1: remove leaf
            if (temp->left == NULL && temp->right == NULL) {
                if (parent->left == temp) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                delete temp;
                return;
            } 
            //case2: one child
            else if ((temp->left == NULL && temp->right !=NULL) || (temp->left != NULL && temp->right == NULL)){
                if (temp->left == NULL && temp->right != NULL){
                    //right child present
                    if (parent->left == temp) {
                        parent->left = temp -> right;
                    } else {
                        parent->right = temp->right;
                    }
                } else{
                    //left child present
                    if (parent ->left == temp) {
                        parent->left = temp ->left;
                    } else {
                        parent->right = temp -> left;
                    }
                }
                delete temp;
                return;
            } else {
               //case3: node has two children
                
            }

        }

};

int main(){
    return 0;
}