#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node * next = nullptr;

  Node (int d) {
    data = d;
  }
};

int main () {
  Node * head = new Node(5);
  cout << head->data << endl;
  return 0;
}
