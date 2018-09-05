#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;
void insertAtNthPosition(int data, int n);
void printList();
Node *createNewNode();
void printList(Node *head);

Node *createNewNode(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void insertAtNthPosition(int data, int n) {
    Node *newNode = createNewNode(data);
    Node *nMinusOnethNode = head;
    if(n == 1 || !head) {
        newNode -> next = head;
        head = newNode;
        return;
    }
    for(int i = 0; i < n - 2; i++) {
        nMinusOnethNode = nMinusOnethNode -> next;
    }
    newNode -> next = nMinusOnethNode -> next;
    nMinusOnethNode -> next = newNode;
}

void printList() {
    Node *headDuplicate = head; 
    while(headDuplicate) {
        cout << headDuplicate -> data << " ";
        headDuplicate = headDuplicate -> next;
    }
    cout << endl;
}

void printList(Node *head) {
    if(!head) {
        cout << endl;
        return;
    }
    cout << head -> data << " ";
    printList(head -> next);
}

int main() {
    int numberOfOperations, data, position;
    cin >> numberOfOperations;
    while(numberOfOperations--) {
        cin >> data >> position;
        insertAtNthPosition(data, position);
        printList();
    }
    cout << "Final State of Linked List" << endl;
    printList(head);
    return 0;
}