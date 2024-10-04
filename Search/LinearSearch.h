int SortedLinearSearch (vector<int> arr, int target) {
  for (int i=0; i<arr.size(); i++) {
    if (arr[i] == target) return i;
    if (arr[i] > target) break;
  }
  return -1;
}

int UnsortedLinearSearch (vector<int> arr, int target) {
  for (int i=0; i<arr.size(); i++) {
    if (arr[i] == target) return i;
  }
  return -1;
}
