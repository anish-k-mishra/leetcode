class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i = 0; i<n-1; i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(int i = 0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);
            vector<int>vis(n, 0);
            stack<int>st;
            for(int i = 0; i<n; i++){
                if(!vis[i]){
                    dfs(i, adj, vis, st);
                }
            }
            vector<int>dist(n, INT_MAX);
            dist[0] = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                for(auto it:adj[node]){
                    if(dist[node] + 1<dist[it]){
                        dist[it] = dist[node]+1;
                    }
                }
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};