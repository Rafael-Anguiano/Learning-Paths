#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVector (vector<int> nums) {
  cout << "{ ";
  for (int num : nums) cout << num << ' ';
  cout << "}" << endl;
}

class Heap {
  vector<int> nodes;

public:
  void push (int val) {
    this->nodes.push_back(val);

    // Check if it is right or left
    int index = this->nodes.size() - 1;
    while (index > 0) {
      bool isLeft = index % 2;

      // Select Head
      int headIndex;
      if (isLeft)  headIndex = (index - 1) / 2;
      if (!isLeft) headIndex = (index - 2) / 2;

      // Swap with head
      if (this->nodes[headIndex] < this->nodes[index]){
        swap(this->nodes[index], this->nodes[headIndex]);
        index = headIndex;
        continue;
      } else {
        break;
      }
    }
  }

  int pop () {
    if (this->nodes.size() == 0) return -1;
    int returnValue = this->nodes[0];

    // Pop element
    swap(this->nodes[0], this->nodes[this->nodes.size() - 1]);
    this->nodes.pop_back();

    // Fix Tree
    int index = 0, left, right, toSwap;

    while (index < this->nodes.size()) {
      left = index * 2 + 1;
      right = index * 2 + 2;
      toSwap = index;

      if (left < this->nodes.size() && this->nodes[left] > this->nodes[index])
        toSwap = left;
      if (right < this->nodes.size() && this->nodes[right] > this->nodes[toSwap])
        toSwap = right;

      if (toSwap == index) break;

      swap(this->nodes[index], this->nodes[toSwap]);
      index = toSwap;
    }
    return returnValue;
  }

  vector<int> getHeap (bool printing= false) {
    if (printing) {
      cout << "{ ";
      for (int num : this->nodes) cout << num << ' ';
      cout << "}" << endl;
    }
    return this->nodes;
  }
};

int main () {

  Heap* hp = new Heap();

  hp->push(1);
  hp->getHeap(true);
  hp->push(2);
  hp->getHeap(true);
  hp->push(3);
  hp->getHeap(true);
  hp->push(5);
  hp->getHeap(true);
  hp->push(10);
  hp->getHeap(true);
  hp->push(0);
  hp->getHeap(true);

  cout << hp->pop() << endl;
  hp->getHeap(true);
  cout << hp->pop() << endl;
  hp->getHeap(true);
  cout << hp->pop() << endl;
  hp->getHeap(true);
  cout << hp->pop() << endl;
  hp->getHeap(true);
  cout << hp->pop() << endl;
  hp->getHeap(true);
  cout << hp->pop() << endl;
  hp->getHeap(true);
  cout << hp->pop() << endl;
  hp->getHeap(true);


  return 0;
}
