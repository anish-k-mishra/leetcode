class Solution {
public:
    bool solve(int start, int n, vector<vector<int>>& graph, vector<int>& v){
        v[start] = 0;
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:graph[node]){//already the node is not coloured
                if(v[i] == -1){
                    v[i] = !v[node];
                    q.push(i);
                }
                else if(v[i] == v[node]){//the node and its neighbour are coloured in same color
                    return false;
                }
            }        
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>v(n, -1);

        for(int i = 0; i<n ;i++){
            if(v[i] == -1){
                if(solve(i, n, graph, v) == false){
                    return false;
                }
            }
        }
        return true;
    }
};