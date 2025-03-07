/*
* QuickSelect
*
* QuickSelect is a selection algorithm to find the k-th smallest element in an unordered list.
* It is related to the quick sort sorting algorithm.
*/
#include <iostream>
#include <vector>

using namespace std;

int quickSelect (vector<int> & nums, int left, int right, int & indexSearched) {
  if (indexSearched > nums.size()) return -1;
  int pivot = nums[right]; // The pivot is the value we will use to compare
  int p = left; // The pointer moving to right

  for (int i = left; i < right; i++) {
    if (nums[i] <= pivot) {
      swap(nums[i], nums[p]);
      p++;
    }
  }

  swap(nums[p], nums[right]);
  if (p > indexSearched) return quickSelect(nums, left, p - 1, indexSearched);
  if (p < indexSearched) return quickSelect(nums, p + 1, right, indexSearched);

  return nums[p];
}


int main () {
  vector<int> nums = {6,5,2,4,7,8,9,1,0,3};

  int kLargestElement = 3;
  int searchedIndex = nums.size() - kLargestElement;

  int result = quickSelect(nums, 0, nums.size()-1, searchedIndex);
  cout << result << endl;

  return 0;
}
