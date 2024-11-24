#include <iostream>
#include <vector>

using namespace std;

vector<int> merge (vector<int> a, vector<int> b) {
  int count = 0;
  vector<int>c;
  while (!a.empty() && !b.empty()) {
    if (a[0] <= b[0]) {
      c.push_back(a[0]);
      a.erase(a.begin());
    }
    if (b[0] < a[0]) {
      c.push_back(b[0]);
      b.erase(b.begin());
      count += a.size();
    }
  }
  for (int & n : a) {
    c.push_back(n);
  }
  for (int & n : b) {
    c.push_back(n);
  }
  c.push_back(count);
  return c;
}

int numberOfPermutations (vector<int> & v) {
  if (v.size() == 1) return 0;
  vector<int> A;
  vector<int> B;
  for (int i=0; i<v.size(); i++) {
    if (i < v.size()/2) {
      A.push_back(v[i]);
    } else {
      B.push_back(v[i]);
    }
  }

  int a = numberOfPermutations(A);
  int b = numberOfPermutations(B);

  v = merge(A, B);
  int c = v[v.size()-1];
  v.pop_back();
  return c + a + b;
}

int main () {
  vector<int> nums = {1,3,2,4};
  cout << numberOfPermutations(nums) << endl;
}
