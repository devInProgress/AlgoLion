#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void printDLL() {
    Node *headDuplicate = head; 
    while(headDuplicate) {
        cout << headDuplicate -> data << " ";
        headDuplicate = headDuplicate -> next;
    }
    cout << endl;
}

Node *createNewNode(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
}

void InsertAtBeginningOfDLL(int data) {
    Node *newNode = createNewNode(data);
    if(!head) {
        head = newNode;
        return;
    }
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

int main() {
    int n, data;
    cin >> n;
    while(n--) {
        cin >> data;
        InsertAtBeginningOfDLL(data);
        printDLL();
    }
    return 0;
}

