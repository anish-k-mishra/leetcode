class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int rig = INT_MAX, down = INT_MAX;
        if(j+1 < grid[0].size()){
            rig = grid[i][j] + solve(i, j+1, grid, dp);
        }
        if(i+1 < grid.size()){
            down = grid[i][j]+solve(i+1, j, grid, dp);
        }
        return dp[i][j] = min(rig, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1, vector<int>(grid[0].size(), -1));
        return solve(0, 0, grid, dp);
    }
};