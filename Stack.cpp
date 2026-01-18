#include <iostream>
using namespace std;

const int STACK_MAX = 100;
template <class T>
class Stack{
    private:
    T data[STACK_MAX];
    int size;
    public:
    Stack(){
        size = 0;
    }
    void destroy(){
        size = 0;
    }
    void push(T value) {
        if(size < STACK_MAX) {
            data[size] = value;
            size++;
        } else {
            cout <<"Stack is full!" << endl;
        }
    }
    void pop(){
        if(size != 0) {
            size--;
        } else {
            cout <<"Stack is empty!" << endl;
        }
    }
    T popValue(){
        if(size!= 0) {
            cout<<"Delete" << endl;
            size--;
            return data[size];
        } else {
            return 0;
        }
    }

    T top(){
        if(size != 0) {
            return data[size-1];
        } else {
            return 0;
        }
    }

    bool isEmpty(){
        return size==0;
    }

    bool balanced_braces (string exp) {
        Stack <char> s;
        for(int i = 0; i < exp.length(); i++) {
            if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
                s.push(exp[i]);
            } else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
                if(s.isEmpty() || !matching(s.top(),exp[i])) {
                    return false;
                } else {
                    s.pop();
                }   
            }
        }
        return s.isEmpty();
    }
    bool matching(char x, char y) {
        if(x=='{' && y=='}') {
            return true;
        } else if(x=='[' && y==']') {
            return true;
        } else if(x=='(' && y==')') {
            return true;
        } else {
            return false;
        }
    }

    int cacl_Postfix(string exp) {
        Stack<int> s;
        for (int i =0; i < exp.length(); i++) {
            if(exp[i]>='0' && exp[i] <= '9') {
                s.push(exp[i] - '0');
            } else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                switch(exp[i]) {
                    case '+': s.push(b + a); break;
                    case '-': s.push(b - a); break;
                    case '*': s.push(a *b); break;
                    case '/': s.push(b / a); break;
                }
            }
        }
        return s.top();
    }

    void display(){
        for(int i = size - 1; i >= 0; i--){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};


int main(){

    Stack <int> s1;
    s1.push(10);
    s1.push(9);
    s1.push(8);
    cout << s1.top() << endl;
    cout << s1.popValue() << endl;
    cout << s1.top() << endl;

    cout << s1.balanced_braces("{{0002320(339432)}}") << endl; //1
    cout << s1.balanced_braces("{{0002320(339432)}") << endl; //0
    cout << s1.balanced_braces("[()()][{{}}]") << endl; //1
    cout << s1.balanced_braces("[()(][{{}]") << endl; //0
    cout << s1.balanced_braces("{}[]()(})") << endl; //0

    string exp = "12-2*2*2/";
    string exp1 = "55/2+19*-";
    cout << "Answer: " << s1.cacl_Postfix(exp) << endl;
    cout << "Answer: " << s1.cacl_Postfix(exp1) << endl;

    s1.display();




    return 0;
}