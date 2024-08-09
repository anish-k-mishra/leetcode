class Solution {
public:
    int findRsum(vector<vector<int>>&grid, int r, int c){
        vector<bool>vis(10);
        int sum = 0;
        for(int i = 0; i<3; i++){
            int rowSum = 0;
            for(int j = 0; j<3; j++){
                int val = grid[r+i][c+j];
                if(vis[val] == 1 || val == 0 || val>9 ){
                    return -1;
                }
                rowSum += val;
                vis[val] = 1;
            }
            if(i == 0){
                sum = rowSum;
            }
            else{
                if(rowSum != sum){
                    return -1;
                }
            }
        }
        return sum;
    }
    int findCsum(vector<vector<int>>&grid, int r, int c){
        int sum = 0;
        for(int i = 0; i<3; i++){
            int colSum = 0;
            for(int j = 0; j<3; j++){
                int val = grid[r+j][c+i];
                colSum += val;
            }
            if(i == 0){
                sum = colSum;
            }
            else{
                if(colSum != sum){
                    return -1;
                }
            }
        }
        return sum;
    }
    int diagSum(vector<vector<int>>&grid, int r, int c){
        int diag1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int diag2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        if(diag1 == diag2){
            return diag1;
        }
        return -1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row<3 || col <3){
            return 0;
        }
        int cnt = 0;
        for(int i = 0; i<grid.size()-2; i++){
            for(int j = 0; j<grid[0].size()-2; j++){
                int rsum = findRsum(grid, i, j);
                int csum = findCsum(grid, i, j);
                int dsum = diagSum(grid, i, j);
                if(rsum == csum && rsum == dsum && rsum != -1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};