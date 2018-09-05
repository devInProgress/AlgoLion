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
void deleteAtNthPosition(int position);

Node *createNewNode(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void reverseLinkedListIteratively() {
    Node *currentNode = head, *previousNode = NULL, *nextNode;
    while(currentNode) {
        nextNode = currentNode -> next;
        currentNode -> next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    head = previousNode;
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

void deleteAtNthPosition(int position) {
    if(position >= 1 && !head) {
        cout << "The linked list is empty, Unable to delete from an empty list!" << endl;
        return;
    }
    if(position == 1) {
        Node *headDuplicate = head;
        Node *secondNode = headDuplicate -> next;
        head = secondNode;
        delete headDuplicate;
        return;
    }
    Node *nthMinusOnePosition = head; 
    for(int i = 0; i < position - 2; i++) {
        nthMinusOnePosition = nthMinusOnePosition -> next;
    }
    Node *nthPosition = nthMinusOnePosition -> next;
    nthMinusOnePosition -> next = nthPosition -> next;
    delete nthPosition;
}

void printList() {
    Node *headDuplicate = head; 
    while(headDuplicate) {
        cout << headDuplicate -> data << " ";
        headDuplicate = headDuplicate -> next;
    }
    cout << endl;
}

int main() {
    int numberOfInsertOperations, numberOfDeleteOperations, data, position;
    cin >> numberOfInsertOperations;
    while(numberOfInsertOperations--) {
        cin >> data >> position;
        insertAtNthPosition(data, position);
        printList();
    }
    reverseLinkedListIteratively();
    printList();
    return 0;
}