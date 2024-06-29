/**
* Sort Stack
* Write a program to sort a stack in ascending order (with biggest items on top).
* You may use at most one additional stack to hold items, but you may not copy the
* elements into any other data structure (such as an array). The stack supports the
* following operations: push, pop, peek, and isEmpty.
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
  StackNode * top = nullptr;
public:
  void push (int data) {
    StackNode * newNode = new StackNode(data);
    newNode->next = top;
    top = newNode;
  }
  int pop () {
    if (top == nullptr) return -1;
    int data = top->data;
    top = top->next;
    return data;
  }
  int peek () {
    if (top == nullptr) return -1;
    return top->data;
  }
  bool isEmpty () {
    return top == nullptr;
  }
};

class SortStack {
  class StackNode {
  public:
    int data;
    StackNode * next = nullptr;
    StackNode (int data) {
      this->data = data;
    }
  };

public:
  StackNode * top = nullptr;
  Stack * stack = new Stack();

  void push (int item) {
    while (top != nullptr && item > top->data) {
      stack->push(top->data);
      top = top->next;
    }
    StackNode * newNode = new StackNode(item);
    newNode->next = top;
    top = newNode;
    while (!stack->isEmpty()) {
      newNode = new StackNode(stack->pop());
      newNode->next = top;
      top = newNode;
    }
  }

  int pop () {
    if (top == nullptr) return -1;
    int data = top->data;
    top = top->next;
    return data;
  }

  int peek () {
    if (top == nullptr) return -1;
    return top->data;
  }

  bool isEmpty () {
    return top == nullptr;
  }
};

int main () {
  SortStack * stack = new SortStack();
  stack->push(5);
  stack->push(3);
  stack->push(4);
  stack->push(1);
  stack->push(8);
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  return 0;
}



