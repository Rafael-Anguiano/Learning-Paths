/**
 * Longest Increasing Subarray
 *
 * Problem: Find the length of the longest subarray where elements are in
 * strictly increasing order.
 *
 * Example 1:
 * Input: [1, 3, 5, 4, 7]
 * Output: 3
 * Explanation: The longest increasing subarray is [1, 3, 5] with length 3.
 *
 * Example 2:
 * Input: [2, 2, 2, 2]
 * Output: 1
 * Explanation: Each element by itself forms a subarray of length 1.
 */

#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubArr(std::vector<int> array) {
  if (array.size() == 0)
    return 0;

  int result{0};
  int counter{1};

  for (int i = 1; i < array.size(); i++) {
    if (array[i] <= array[i - 1]) {
      if (counter > result)
        result = counter;
      counter = 1;
    } else {
      counter++;
    }
  }
  if (counter > result)
    result = counter;

  return result;
}

int main() {
  vector<int> example1{1, 3, 5, 4, 7};
  cout << "Example 1" << endl;
  cout << "Expected: 3" << endl
       << "Got: " << longestIncreasingSubArr(example1) << endl
       << endl;

  vector<int> example2{2, 2, 2, 2};
  cout << "Example 2" << endl;
  cout << "Expected: 1" << endl
       << "Got: " << longestIncreasingSubArr(example2) << endl;
  return 0;
}
