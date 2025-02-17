/*
 * Implement a data structure that has the following methods:
 * push(int) pushes an element into the data structure
 * get_median() -> int gets the median of the elements in the data structure.
 *
 *
 * push(1)
 * get_median() -> 1
 * push(2)
 * get_median() -> 1.5
 * push(2)
 * get_median() -> 2
 *
 *
 * 1 -> 1/2 -> 0
 * if (sizeIsEven) {
 	getTwoNodes
 }
 * 1, 2 -> 2/2 -> 1
 *
 * priority_queue
 * size
 *
 * priority_queue.pop() O(logn)
 * 50 / 2 -> 25
 * O(n*logn)
 *            *
 * [1,|  2, | 3, 4, 5]
 * stack: [1, 2] -> [1 ] -> []
 * priority_queue.push() O(logn)
 * O(n*logn)
 *
 *
 * List:
 *  - Sorted -> find a way to get the middle as fast as possible;
 *  - push: O(n)
 *  - get_median: O(1)
 *
 	1.5 - 1 = 0
 *
 * push(2)
 * push(3)
 * push(4)
 * push(5)
 * push(2)
 * desc *
 * q1: [2, 2, 1]
 * asc  *
 * q2: [3, 4, 5]
 * We want our queues to be balanced, when even they should have the same size
 * We want to have lower half in one queue and higher half in another queue
 */

#include <queue>
#include <functional>
using namespace std;

class Median {
  priority_queue<int, vector<int>> desc;
  priority_queue<int, vector<int>, greater<int>> asc;

  public:
  	void push(int number) {
      	this.desc.push(number);
      	if (abs(this.desc.size() - this.asc.size()) < 2) 
          return;
        this.asc.push(this.desc.top());
        this.desc.pop();
    }

    double get_median() {
      if (this.desc.size() != this.asc.size()) 
        return (this.desc.top() + this.asc.top()) / 2;
      return this.desc.top();
    }
};

