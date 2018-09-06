#include <bits/stdc++.h>
#define MAX_SIZE 101
using namespace std;

int Stack[MAX_SIZE] = {0};
int top = -1;

void push(int data) {
    if(top == MAX_SIZE - 1) {
        cout << "Stack Overflows! cannot insert element" << endl;
        return;
    }
    Stack[++top] = data;
}

int pop() {
    if(top == -1) {
        cout << "Stack Underflows! cannot pop element" << endl;
        return -1;
    }
    return Stack[top--];
}

int peek() {
    return Stack[top];
}

void printCurrentStackElements() {
    if(top == -1) {
        return;
    }
    for(int i = 0; i <= top; i++) {
        cout << Stack[i] << " ";
    }
    cout << endl;
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


