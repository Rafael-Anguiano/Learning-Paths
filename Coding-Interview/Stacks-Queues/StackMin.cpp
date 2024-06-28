/**
* Stack Min
* Implement a stack that has a min() function that returns the minimum element in the stack.
* All operations should be O(1)
*/

#include <iostream>
#include <limits.h>

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
      if(top == nullptr) return INT_MAX;
      return top->data;
    }
};

class StackMin {
  class StackMinNode {
    public:
      int data;
      StackMinNode * next = nullptr;

      StackMinNode (int data) {
        this->data = data;
      }
  };

  StackMinNode * top;
  Stack * arr = new Stack();

  public:
    int pop() {
      if(top == nullptr) return 0;
      int item = top->data;
      top = top->next;
      arr->pop();
      return item;
    }
    void push(int item) {
      StackMinNode * t = new StackMinNode(item);
      t->next = top;
      top = t;
      arr->push(arr->peak() < item ? arr->peak() : item);
    }
    int peak () {
      if(top == nullptr) return INT_MAX;
      return top->data;
    }
    int min () {
      return arr->peak();
    }
};

int main () {
  StackMin * arr = new StackMin();
  arr->push(5);
  cout << arr->min() << endl;
  arr->push(6);
  cout << arr->min() << endl;
  arr->push(3);
  cout << arr->min() << endl;
  arr->push(7);
  cout << arr->min() << endl;
  arr->pop();
  cout << arr->min() << endl;
  arr->pop();
  cout << arr->min() << endl;
  return 0;
}
