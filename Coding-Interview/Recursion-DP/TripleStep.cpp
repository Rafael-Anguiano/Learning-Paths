/*
* Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
* Implement a method to count how many possible ways the child can run up the stairs.
*/


#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int>results {{1,1}, {2,1}, {3,1}};

int possibleWaysToStair (int stairSize) {
  if (results.count(stairSize)) return results[stairSize];

  results[stairSize] = possibleWaysToStair(stairSize - 1) + possibleWaysToStair(stairSize - 2) + possibleWaysToStair(stairSize - 3);

  return results[stairSize];
}

int main () {
  cout << "Stair Size 5: " << possibleWaysToStair(5) << endl;
  cout << "Stair Size 8: " << possibleWaysToStair(8) << endl;
  cout << "Stair Size 3: " << possibleWaysToStair(3) << endl;
  cout << "Stair Size 2: " << possibleWaysToStair(2) << endl;
  cout << "Stair Size 10: " << possibleWaysToStair(10) << endl;

  return 0;
}
