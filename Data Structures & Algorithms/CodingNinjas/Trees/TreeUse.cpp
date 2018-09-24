#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
  int rootData, n, childData;
  cout << "Enter root data" << endl;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);
  queue<TreeNode<int> *> q;
  q.push(root);
  while(!q.empty()) {
    TreeNode<int> *front = q.front();
    q.pop();
    cout << "Enter the number of children for " << front->data << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << "Enter the " << i + 1 << "th child of " << front->data << endl;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      q.push(child);
    }
  }
  return root;
}

TreeNode<int>* takeInput() {
  int rootData, n;
  cout << "Enter data" << endl;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);
  cout << "Enter number of children of " << rootData << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    root->children.push_back(takeInput());
  }
  return root;
}

void printTree(TreeNode<int> *root) {
  if(!root) {
    return;
  }
  cout << root->data << ": ";
  for (int i = 0; i < root->children.size(); i++) {
    cout << root->children[i]->data;
    if(i != root->children.size() - 1) {
      cout << ", ";
    }
  }
  cout << endl;
  for (int i = 0; i < root->children.size(); i++)
  {
    printTree(root->children[i]);
  }
}

int main() {
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 = new TreeNode<int>(3);
  // root->children.push_back(node1);
  // root->children.push_back(node2);
  TreeNode<int> *root = takeInputLevelWise();
  printTree(root);
  return 0;
}