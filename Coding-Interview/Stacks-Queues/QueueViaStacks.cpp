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
  Stack * one,* two;

  void shiftTracks () {
    if(two->isEmpty()) {
      while (!one->isEmpty()) {
        two->push(one->pop());
      }
    }
  }

public:
  QueueViaStacks () {
    one = new Stack();
    two = new Stack();
  }

  void enQueue (int item) {
    one->push(item);
  }

  int deQueue () {
    shiftTracks();
    if (two->isEmpty()) return -1;
    return two->pop();
  }

  int peak () {
    shiftTracks();
    if (two->isEmpty()) return -1;
    return two->peek();
  }
  bool isEmpty () {
    return one->isEmpty() && two->isEmpty();
  }
};

int main () {
  QueueViaStacks * q = new QueueViaStacks();
  q->enQueue(1);
  q->enQueue(2);
  q->enQueue(3);
  cout << q->deQueue() << endl;
  q->enQueue(4);
  q->enQueue(5);
  cout << q->deQueue() << endl;
  cout << q->deQueue() << endl;
  cout << q->deQueue() << endl;
  q->enQueue(6);
  cout << q->deQueue() << endl;
  return 0;
}
