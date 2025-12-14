/**
 * Write a function that receive an array of integers and return the array with
 * the even values first
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * (in-place) Function to rearrange array with evenfirst
 * @param vector<int> The array to fix
 * @return vector<int> the array with the even first
 */
void evenFirst(vector<int> &arr) {
  int i = 0, j = arr.size() - 1;
  int temp{0};
  while (i < j) {
    if (arr[i] % 2 != 0 && arr[j] % 2 == 0) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j++;
    } else {
      if (arr[i] % 2 == 0)
        i++;
      if (arr[j] % 2 != 0)
        j--;
    }
  }
}

void printVector(vector<int> arr) {
  for (int i : arr) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  vector<int> test = {-1, 2, 2, 3, 4, 5};
  evenFirst(test);
  printVector(test);
  return 0;
}
