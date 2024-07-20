class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>ans;
        int n = rowSum.size();
        int m = colSum.size();
        for(int i = 0; i<n; i++){
            vector<int>temp;
            for(int j = 0; j<m; j++){
                int mini = min(rowSum[i], colSum[j]);
                temp.push_back(mini);
                rowSum[i] = rowSum[i] - mini;
                colSum[j] = colSum[j] - mini;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};