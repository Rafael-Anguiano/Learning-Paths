/**
* Queue via Stacks:
* Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>

using namespace std;

class Stack {
  class StackNode {
  public:
    int data;
    StackNode * next = nullptr;
    StackNode (int d){
      this->data = d;
    }
  };
  StackNode * top = nullptr;

  public:
  void push (int item) {
    StackNode * t = new StackNode(item);
    t->next = top;
    top = t;
  }

  int pop () {
    if (top == nullptr) return -1;
    int item = top->data;
    top = top->next;
    return item;
  }

  int peek () {
    if (top == nullptr) return -1;
    return top->data;
  }

  bool isEmpty () {
    return top == nullptr;
  }
};

class QueueViaStacks {
  Stack * one = new Stack();
  Stack * two = new Stack();


public:
  void enQueue (int item) {
    one->push(item);
  }

  int deQueue () {
    if (one->isEmpty()) return -1;
    while (!one->isEmpty()) {
      two->push(one->pop());
    }
    int item = two->peek();
    two->pop();
    while (!two->isEmpty()) {
      one->push(two->pop());
    }
    return item;
  }

  int peak () {
    if (one->isEmpty()) return -1;
    while (!one->isEmpty()) {
      two->push(one->pop());
    }
    int item = two->peek();
    while (!two->isEmpty()) {
      one->push(two->pop());
    }
    return item;
  }
  bool isEmpty () {
    return one->isEmpty();
  }
};

int main () {
  QueueViaStacks * q = new QueueViaStacks();
  q->enQueue(1);
  q->enQueue(2);
  q->enQueue(3);
  q->enQueue(4);
  q->enQueue(5);
  q->enQueue(6);
  cout << q->deQueue() << endl;
  cout << q->deQueue() << endl;
  cout << q->deQueue() << endl;
  cout << q->deQueue() << endl;
  cout << q->deQueue() << endl;
  return 0;
}
