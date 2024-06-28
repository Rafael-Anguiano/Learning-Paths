/**
* Stack Implementation
*/

#include <iostream>

using namespace std;

class Stack {
  class StackNode {
  public:
    int data;
    StackNode * next = nullptr;
    StackNode (int data) {
      this->data = data;
    }
  };
  StackNode * top;
  public:
    int pop() {
      if(top == nullptr) return 0;
      int item = top->data;
      top = top->next;
      return item;
    }
    void push(int item) {
      StackNode * t = new StackNode(item);
      t->next = top;
      top = t;
    }
    int peak () {
      if(top == nullptr) return 0;
      return top->data;
    }
    bool isEmpty () {
      return top == nullptr;
    }
};

int main () {
  Stack * arr = new Stack();
  arr->push(5);
  cout << arr->peak() << endl;
  arr->push(6);
  cout << arr->peak() << endl;
  arr->push(3);
  cout << arr->peak() << endl;
  arr->push(7);
  cout << arr->peak() << endl;
  return 0;
}
