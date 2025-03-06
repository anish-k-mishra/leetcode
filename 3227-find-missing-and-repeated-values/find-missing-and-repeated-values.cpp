class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size()*grid[0].size();
        vector<int>vis(n+1, 0);
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                vis[grid[i][j]]++;
            }
        }
        vector<int>ans;
        bool rev = 0;
        for(int i = 1; i<vis.size(); i++){
            if(vis[i] == 2){
                ans.push_back(i);
            }
            else if(vis[i] == 0){
                ans.push_back(i);
                if(ans.size() == 1){
                    rev = 1;
                }
            }
        }
        if(rev == 1){
            swap(ans[0], ans[1]);
        }
        return ans;
    }
};