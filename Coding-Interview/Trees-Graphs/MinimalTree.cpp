/*
* Minimal Tree:
* Given a sorted (increasing order) array with unique integer elements,
* Write an algorithm to create a binary search tree with minimal height.
*
* Example:
* Input: {1, 2, 3, 4, 5, 6, 7}
* Output: A binary search tree with minimal height.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
    }
};

Node * createMinimalTree (vector<int> arr) {
  Node * head = new Node(arr[arr.size()/2]);

  cout << head->data << endl;

  if (arr.size() <= 1) return head;

  vector<int>arrLeft;
  vector<int>arrRight;
  for (int i=0; i<arr.size(); i++) {
    if (i < arr.size()/2) arrLeft.push_back(arr[i]);
    if (i > arr.size()/2) arrRight.push_back(arr[i]);
  }

  if (arrLeft.size()) head->left = createMinimalTree(arrLeft);
  if (arrRight.size()) head->right = createMinimalTree(arrRight);

  return head;
}

void printTreeByLevel (Node * root) {
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i=0; i<size; i++) {
      Node * node = q.front();
      q.pop();
      cout << node->data << " ";
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    cout << endl;
  }
}

int main () {
  // Test 1:
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node * tree = createMinimalTree(arr);
  printTreeByLevel(tree);

  // Test 2:
  vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Node * tree2 = createMinimalTree(arr2);
  printTreeByLevel(tree2);


  return 0;
}
