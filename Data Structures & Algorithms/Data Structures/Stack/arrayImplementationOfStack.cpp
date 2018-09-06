#include <bits/stdc++.h>
#define MAX_SIZE 101
using namespace std;

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if(top == MAX_SIZE - 1) {
        cout << "Stack Overflows! cannot insert element" << endl;
        return;
    }
    stack[++top] = data;
}

int pop() {
    if(top == -1) {
        cout << "Stack Underflows! cannot pop element" << endl;
        return -1;
    }
    return stack[top--];
}

int peek() {
    return stack[top];
}

void printCurrentStackElements() {
    if(top == -1) {
        return;
    }
    for(int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, option, data;
    cout << "How many stack operations do you want to perform?" << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Indicate 1 for push and 2 for pop" << endl;
        cin >> option;
        if(option == 1) {
            cout << "Enter Element to be pushed onto the stack" << endl;
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


