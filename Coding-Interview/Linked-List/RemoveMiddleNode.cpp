/**
* Remove Middle Node
* Search and delete thee middle node in a LinkedList
* Example:
* Input: 1 -> 2 -> 3 -> 4 -> 5
* Output: 1 -> 2 -> 4 -> 5
*/

#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next = nullptr;
    Node(int d) {
      this->data = d;
    }

    void print() {
      Node *n = this;
      while (n != nullptr) {
      cout << n->data << " ";
      n = n->next;
      }
      cout << endl;
    }
};

void removeMiddle(Node * head) {
  Node * slow = head;
  Node * fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->data = slow->next->data;
  slow->next = slow->next->next;
}

int main () {
  // Example 1
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  head->print();
  removeMiddle(head);
  head->print();

  return 0;
}
