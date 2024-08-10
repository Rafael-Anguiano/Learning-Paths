/**
* Check Balanced
* Implement a function to check if a binary tree is balanced.
* For the purposes of this question:
* A balanced tree is defined to be a tree such that 
* the heights of the two subtrees of any node 
* never differ by more than one.
*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node (int d) {
    this->data = d;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> checkIfBalanced (Node* head) {
  if (!head) return {1, 0};

  vector<int> left = checkIfBalanced(head->left);
  vector<int> right = checkIfBalanced(head->right);

  if (!left[0] || !right[0] || abs(left[1]-right[1] > 1))
    return {0, max(left[1], right[1])};

  return {1, max(left[1], right[1])+1};
}

bool isBalanced (Node* head) {
  return checkIfBalanced(head)[0];
}

int main () {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->left->left = new Node(6);
  root->left->left->left->left = new Node(7);

  bool result = isBalanced(root);
  string resultString = result ? "True" : "False";
  cout << "Balanced: " << resultString << endl;

  return 0;
}
