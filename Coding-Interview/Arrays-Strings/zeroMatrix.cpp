/**
* Zero Matrix
* Write an algorithm such that if an element in an MxN matrix is 0, 
* its entire row and column are set to 0.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> zeroMatrix (vector<vector<int>> matrix) {
  vector<int> rows (matrix.size(), 0);
  vector<int> cols (matrix[0].size(), 0);

  for (int i=0; i<matrix.size(); i++) {
    for (int j=0; j<matrix[0].size(); j++) {
      if (!matrix[i][j]) {
        rows[i]++;
        cols[j]++;
      }
    }
  }
  for (int i=0; i<matrix.size(); i++) {
    for (int j=0; j<matrix[0].size(); j++) {
      if (rows[i] || cols[j]) matrix[i][j] = 0;
      continue;
    }
  }
  return matrix;
}

int main () {
  // Test cases
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 0, 6},
    {7, 8, 9}
  };
  matrix = zeroMatrix(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
 
  return 0;
}
