/**
* Stack of Plates: 
* Imagine a (literal) stack of plates. 
* If the stack gets too high, it might topple.
* Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
* Implement a data structure SetOfStacks that mimics this. 
* SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
* SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop () should return the same values as it would if there were just a single stack).
* FOLLOW UP
* Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/


#include <iostream>
#include <vector>

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
    int size = 0;
    void push (int data) {
      StackNode * newNode = new StackNode(data);
      newNode->next = top;
      top = newNode;
      size++;
    }
    int pop () {
      if (top == nullptr) return -1;
      int data = top->data;
      top = top->next;
      size--;
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

class SetOfStacks {
public:
  int threshold;
  vector<Stack*> stacks;

  SetOfStacks (int threshold) {
    this->threshold = threshold;
  }

  void push (int item) {
    if (!stacks.size() || stacks[stacks.size()-1]->size >= threshold) stacks.push_back(new Stack());
    stacks[stacks.size()-1]->push(item);
  }
  int pop () {
    int data = stacks[stacks.size()-1]->pop();
    if (stacks[stacks.size()-1]->isEmpty()) stacks.pop_back();
    return data;
  }

  int popAt (int index) {
    return stacks[index]->pop();
  }

  bool isEmpty () {
    return !!stacks.size();
  }
};



int main () {
  SetOfStacks * plates = new SetOfStacks(4);
  plates->push(1);
  plates->push(2);
  plates->push(3);
  plates->push(4);
  plates->push(5);
  plates->push(6);
  plates->push(1);
  plates->push(7);

  cout << plates->popAt(0) << endl;
  cout << plates->pop() << endl;
  cout << plates->pop() << endl;
  cout << plates->pop() << endl;
  cout << plates->pop() << endl;
  cout << plates->pop() << endl;
  cout << plates->pop() << endl;
  cout << plates->pop() << endl;

  return 0;
}

