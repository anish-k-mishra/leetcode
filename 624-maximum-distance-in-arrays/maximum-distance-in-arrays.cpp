class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0][arrays[0].size()-1];
        int res = 0;
        for(int i = 1; i<arrays.size(); i++){
            int n = arrays[i].size();
            res = max(res, max(arrays[i][n-1] - mini, maxi - arrays[i][0]));

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][n-1]);
        }
        return res;
    }
};