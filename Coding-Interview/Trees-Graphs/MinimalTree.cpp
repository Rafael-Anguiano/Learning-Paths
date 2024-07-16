/*
* Minimal Tree:
* Given a sorted (increasing order) array with unique integer elements,
* write an algorithm to create a binary search tree with minimal height.
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
  Node* head = new Node(arr[0]);
  queue<Node*> q;
  q.push(head);

  for (int i=1; i<arr.size(); i++) {
    Node * leftNode = new Node(arr[i]);
    Node * rightNode = i+1 < arr.size() ? new Node(arr[i+1]) : nullptr;

    q.front()->left = leftNode;
    if (rightNode) q.front()->right = rightNode;
    q.pop();
    q.push(leftNode);
    if (rightNode) q.push(rightNode);

    i = i+1;
  }

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
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node * tree = createMinimalTree(arr);
  printTreeByLevel(tree);
  
  return 0;
}
