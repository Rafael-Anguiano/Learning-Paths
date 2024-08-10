/**
* List Of Depths:
*
* Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth.
*
* Example:
* Input: {  1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
* Output: { 
    1 -> NULL,
    2 -> 3 -> NULL, 
    4 -> 5 -> 6 -> 7 -> NULL, 
    8 -> 9 -> 10 -> NULL 
}
*/

#include <iostream>
#include <queue>
#include <list>
#include <set>
#include <math.h>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int x) {
    this->data = x;
    this->left = nullptr;
    this->right = nullptr;
  }
};

void printList (list<Node*> li) {
  while (!li.empty()) {
    cout << li.front()->data << " -> ";
    li.pop_front();
  }
  cout << "NULL" << endl;
}

void printListOfDepths (vector<list<Node*>> arr) {
  for (int i=0; i<arr.size(); i++) {
    printList(arr[i]);
  }
}

vector<list<Node*>> listOfDepthsByLevel (Node* root) {
  if (root == nullptr) return {};
  vector<list<Node*>> lists;
  list<Node*> curr (1, root);
  lists.push_back(curr);

  for (int i=0; i<lists.size(); i++) {
    list<Node*> copy = lists[i];
    list<Node*> newList;
    while (!copy.empty()) {
      if (copy.front()->left) newList.push_back(copy.front()->left);
      if (copy.front()->right) newList.push_back(copy.front()->right);
      copy.pop_front();
    }
    if (!newList.empty()) lists.push_back(newList);
  }

  return lists;
}

void listOfDepthsRecursive (Node * head, vector<list<Node*>>& arrDFS, int level) {
  if (head == nullptr) return;

  if (arrDFS.size() == level) {
    list<Node*> myList (1, head);
    arrDFS.push_back(myList);
  } else {
    arrDFS[level].push_back(head);
  }

  listOfDepthsRecursive(head->left, arrDFS,level+1);
  listOfDepthsRecursive(head->right, arrDFS, level+1);
}



int main () {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->left->left->left = new Node(8);
  root->left->left->right = new Node(9);
  root->left->right->left = new Node(10);
  root->right->right->right = new Node(11);
  root->right->right->right->left = new Node(12);

  vector<list<Node*>> result = listOfDepthsByLevel(root);

  printListOfDepths(result);

  cout << "------" << endl;

  vector<list<Node*>> arrDFS;
  listOfDepthsRecursive(root, arrDFS, 0);

  printListOfDepths(arrDFS);

  return 0;
}
