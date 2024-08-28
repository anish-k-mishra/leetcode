class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<int>>& vis){
        vis[i][j] = 1;
        bool isSub = true;
        if(!grid1[i][j]){
            isSub = false;
        }
        vector<pair<int, int>>dir{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto it: dir){
            int ni = i+it.first;
            int nj = j+it.second;
            if(ni>=0 && ni<grid1.size() && nj>=0 && nj<grid1[0].size() && !vis[ni][nj] && grid2[ni][nj]){
                if(!dfs(grid1, grid2, ni, nj, vis)){
                    isSub = false;
                }
            }
        }
        return isSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>>vis(grid1.size(), vector<int>(grid1[0].size(), 0));
        int cnt = 0;
        for(int i = 0; i<grid1.size(); i++){
            for(int j = 0; j<grid1[0].size(); j++){
                if(!vis[i][j] && grid2[i][j]){
                    if(dfs(grid1, grid2, i, j, vis)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};