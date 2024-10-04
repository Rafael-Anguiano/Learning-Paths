int BinarySearch (vector<int>arr, int target) {
  int leftIndex = 0;
  int rightIndex = arr.size()-1;
  int n;

  while (leftIndex <= rightIndex) {
    n = leftIndex + floor( (rightIndex - leftIndex)/2 );
    if (target == arr[n]) return n;
    if (target < arr[n]) {
      rightIndex = n - 1;
    } else {
      leftIndex = n+1;
    }
  }
  return -1;
}
