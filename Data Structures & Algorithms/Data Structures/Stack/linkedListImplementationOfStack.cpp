#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

Node *createNewNode(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
}

void push(int data) {
    Node *newNode = createNewNode(data);
    newNode -> next = top;
    top = newNode;
}

void printCurrentStackElements() {
    if(!top) {
        cout << "Nothing to print! stack is empty" << endl;
        return;
    }
    Node *duplicateTop = top;
    while(duplicateTop) {
        cout << duplicateTop -> data << " ";
        duplicateTop = duplicateTop -> next;
    }
    cout << endl;
}

int pop() {
    if(!top) {
        cout << "Stack Underflows! No element found to pop" << endl;
        return -1;
    }
    Node *topNode = top;
    int deletedElement = topNode -> data;
    top = top -> next;
    delete topNode;
    return deletedElement;
}

int main() {
    int n, option, data;
    cout << "How many Stack operations do you want to perform?" << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Indicate 1 for push and 2 for pop" << endl;
        cin >> option;
        if(option == 1) {
            cout << "Enter Element to be pushed onto the Stack" << endl;
            cin >> data;
            push(data);
            cout << "Current State of Stack" << endl;
            printCurrentStackElements();
        } else {
            cout << "Element deleted " << pop() << endl;
            cout << "Current State of Stack" << endl;
            printCurrentStackElements();
        }
    }
}