class Solution {
    private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>&vis){
        vis[node] = 1;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size());
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = 0; j<isConnected[0].size(); j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(isConnected.size(), 0);
        for(int i = 0; i<isConnected.size(); i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;

    }
};