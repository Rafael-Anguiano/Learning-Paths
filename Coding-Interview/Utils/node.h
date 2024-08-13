#include <iostream>

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
  Node(int data, Node* left, Node* right) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};
