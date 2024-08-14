/**
* Successor:
* Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.
* You may assume that each node has a link to its parent.
*
* Example:
* Input:
*          4
*        /  \
*      2     6
*     / \   / \
*    1  3  5  7
*
*     Output: 5
*/

#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;
  Node* parent;

  Node (int d) {
    this->data = d;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
  }
  Node (int d, Node* parent) {
    this->data = d;
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
  }
};

Node* mostLeft (Node* head) {
  if (head->left == nullptr) return head;
  return mostLeft(head->left);
}

Node* nextGreaterParent (Node* head) {
  Node* curr = head;

  while (curr != nullptr) {
    if (curr->data > head->data) return curr;
    else curr = curr->parent;
  }

  return head;
}

Node* successor (Node* head) {
  if (head == nullptr) return nullptr;
  if (head->right != nullptr) return mostLeft(head->right);
  else return nextGreaterParent(head);
}

int main () {
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);

  root->left->parent = root;
  root->right->parent = root;

  root->left->left = new Node(1);
  root->left->right = new Node(3);

  root->left->left->parent = root->left;
  root->left->right->parent = root->left;

  root->right->left = new Node(5);
  root->right->right = new Node(7);

  root->right->left->parent = root->right;
  root->right->right->parent = root->right;

  cout << successor(root->left->left)->data << endl;

  return 0;
}
