/**
* Validate BST
* Given a binary tree, determine if it is a valid binary search tree (BST).
* Assume a BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
* 
* Example 1:
*    Input:
*        2
*      / \
*     1   3
*    Output: true
*
* Example 2:
*    Input:
*          5
*         / \
*        1   4
*       / \
*     3   6
*    Output: false
*    Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
*    is 5 but its right child's value is 4.
*/

#include <iostream>
#include <limits.h>
#include "../Utils/node.h"

using namespace std;

bool checkBST (Node* head, int minVal, int maxVal) {
  if (head == nullptr) return true;
 
  if (
    head->data > maxVal ||
    head->data < minVal
  ) return false;

  return checkBST(head->left, minVal, head->data) &&
         checkBST(head->right, head->data, maxVal);
}

bool isValidBST(Node* root) {
  return checkBST(root, INT_MIN, INT_MAX);
}

int main () {
  Node* root = new Node(2);
  root->left = new Node(1);
  root->right = new Node(3);
  cout << isValidBST(root) << endl;

  Node* root2 = new Node(5);
  root2->left = new Node(1);
  root2->right = new Node(4);
  root2->left->left = new Node(0);
  root2->left->right = new Node(6);
  cout << isValidBST(root2) << endl;

  Node* root3 = new Node(20);
  root3->left = new Node(10);
  root3->right = new Node(30);
  root3->left->left = new Node(5);
  root3->left->right = new Node(15);
  root3->left->left->left = new Node(3);
  root3->left->left->right = new Node(7);
  root3->left->right->right = new Node(17);
  cout << isValidBST(root3) << endl;
  return 0;
}
