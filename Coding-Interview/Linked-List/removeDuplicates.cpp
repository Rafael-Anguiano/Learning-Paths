/**
* Remove Dublicates
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
*/

#include <iostream>
#include <set>

using namespace std;

set<int>h;
class Node {
  public:
    int data;
    Node * next = nullptr;
  Node (int d) {
    data = d;
  }
  void printList () {
    Node * curr = this;
    while (curr != nullptr) {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }
};

void removeDuplicates (Node * root) {
  if(root->next == nullptr) return;

  set<int>h;
  Node * temp;
  while(root->next != nullptr) {
    h.insert(root->data);
    temp = root->next;
    while (h.count(temp->data)) {
      if(temp->next == nullptr) {
        root->next = nullptr;
        return;
      }
      temp = temp->next;
    }
    root->next = temp;
    root = temp;
  }
}

int main () {
  // Test Cases
  Node * head = new Node(1);
  head->next = new Node(1);
  head->next->next = new Node(2);
  head->next->next->next = new Node(3);
  head->next->next->next->next = new Node(3);
  head->printList();
  removeDuplicates(head);
  head->printList();
  return 0;
}
