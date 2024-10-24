class Solution {
  vector<int> dx = {0, 0, 1, -1};
  vector<int> dy = {1, -1, 0, 0};
  int checkPerimeter ( vector<vector<int>>&grid, int row, int  col ) {
    int perimeter = 0;
    for ( int i = 0; i < dx.size(); i++ ) {
      int nx = dx[i] + col;
      int ny = dy[i] + row;
      if (
        nx < 0 || ny < 0 || nx >= grid[0].size() || ny >= grid.size() ||
        grid[ny][nx] != 1
      ) {
        perimeter++;
      }
    }
    return perimeter;
  }
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int p = 0;
    for(int i=0; i < grid.size(); i++) {
      for (int j=0; j< grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          p += checkPerimeter(grid, i, j);
        }
      }
    }
    return p;
  }
};
