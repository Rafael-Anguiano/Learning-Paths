/**
* QuickSort
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector (vector<int>&nums) {
  for (int num : nums) cout << num << " ";
  cout << endl;
}

void quicksort (vector<int> & nums, int left, int right) {
  if (left >= right) return;
  // Choose pivot
  int pivot = nums[right];
  int p = left;

  for (int i=left; i<right; i++) {
    if (nums[i] <= pivot) {
      swap(nums[i], nums[p]);
      p++;
    }
  }

  swap(nums[p], nums[right]);
  quicksort(nums, left, p-1);
  quicksort(nums, p, right);
}



int main () {
  vector<int> nums = {6,5,2,4,7,8,9,1,0,3};

  quicksort(nums, 0, nums.size()-1);
  printVector(nums);

  return 0;
}
