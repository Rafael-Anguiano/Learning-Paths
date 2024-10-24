class Solution {
    vector<vector<int>> visited;
    // right, left, up, down
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void markIsland (vector<vector<char>> & grid, int r, int c) {
        this->visited[r][c] = 1;
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
                grid[ny][nx] == '1' &&
                this->visited[ny][nx] == 0
            ) {
                markIsland(grid, ny, nx);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        this->visited = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    islands++;
                    markIsland(grid, i, j);
                } 
            }
        } 
        return islands;
    }
};
