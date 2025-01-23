class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int cnt = 0;
        vector<int>rowcnt(grid.size(), 0);
        vector<int>colcnt(grid[0].size(), 0);

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    cnt++;
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }

        for(int i = 0;i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    if(rowcnt[i] <=1 && colcnt[j] <=1){
                        cnt--;
                    }
                }
            }
        }

        return cnt;
    }
};