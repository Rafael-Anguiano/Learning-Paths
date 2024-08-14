/**
* Check Subtree:
* T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.
* A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.
* That is, if you cut off the tree at node n, the two trees would be identical.
*/

#include <iostream>
#include "../Utils/node.h"

using namespace std;

bool validateEqualty (Node* t1, Node* t2) {
  if (t1 == nullptr && t2 != nullptr) return false;
  if (t2 == nullptr) return true;

  if (t2->data != t1->data) return false;

  return validateEqualty(t1->left, t2->left) && validateEqualty(t2->right, t2->right);
}

bool checkSubtree (Node* t1, Node* t2) {
  if (t1 == nullptr) return false;

  bool result = false;
  if (t1->data == t2->data) result = validateEqualty(t1, t2);
  if (result) return true;

  return checkSubtree(t1->left, t2) || checkSubtree(t1->right, t2);
}

int main () {
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);


  Node* t2 = new Node(6);
  t2->left = new Node(5);
  t2->right = new Node(7);

  cout << checkSubtree(root, t2) << endl;


  return 0;
}
