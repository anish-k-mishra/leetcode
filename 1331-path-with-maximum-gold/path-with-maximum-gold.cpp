class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& ans, int s, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int row = r + dr[i];
            int col = c + dc[i];
            if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] != 0 && !vis[row][col]) {
                vis[row][col] = 1;
                dfs(grid, row, col, ans, s + grid[row][col], vis);
                vis[row][col] = 0; 
            }
        }
        ans = max(ans, s); 
        return;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> vis(m, vector<int>(n, 0));
                    vis[i][j] = 1; 
                    dfs(grid, i, j, ans, grid[i][j], vis);
                    
                }
            }
        }
        return ans;

    }
};