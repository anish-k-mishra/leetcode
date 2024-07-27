class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&vis, vector<pair<int, int>>&vec, int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row-row0, col-col0});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i = 0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<pair<int, int>>>v;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    vector<pair<int, int>>vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    v.push_back(vec);
                }
            }
        }
        return v.size();
    }
};