// Faster than 100%
class Solution {
    vector<vector<int>> visited;
    priority_queue<int>sizes;
    int curr = 0;
    // right, left, up, down
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void getArea (vector<vector<int>>&grid, int r, int c) {
        visited[r][c] = 1;
        this->curr++;
        int nx;
        int ny;
        for (int i=0; i < 4; i++) {
            nx = dx[i] + c;
            ny = dy[i] + r;
            if (
                ny >= 0 &&
                ny < grid.size() &&
                nx >= 0 &&
                nx < grid[0].size() &&
                grid[ny][nx] == 1 &&
                visited[ny][nx] == 0
            ) {
                getArea(grid, ny, nx);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        this->visited = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    getArea(grid, i, j);
                    this->sizes.push(this->curr);
                    this->curr = 0;
                } 
            }
        } 
        this->sizes.push(0);
        return this->sizes.top();
    }
};
