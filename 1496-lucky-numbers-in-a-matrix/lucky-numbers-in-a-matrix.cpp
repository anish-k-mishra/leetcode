class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int, int>m;
        for(int i = 0; i<matrix.size(); i++){
            int mini = INT_MAX;
            for(int j = 0; j<matrix[0].size(); j++){
                mini = min(mini, matrix[i][j]);
            }
            m[mini]++;
        }
        vector<int>ans;
        for(int j = 0 ; j < matrix[0].size(); j++){
            int maxi = INT_MIN;
            for(int i = 0; i<matrix.size(); i++){
                maxi = max(maxi, matrix[i][j]);
            }
            if(m[maxi] != 0){
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};