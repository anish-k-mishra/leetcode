class Solution {
public:
    static bool customSort(const vector<int>& a, const vector<int>& b) {
        // If the first elements are not the same, sort in ascending order
        if (a[0] != b[0])
            return a[0] < b[0];
        // If the first elements are the same, sort the second elements in descending order
        return a[1] > b[1];
    }
    int solve(vector<vector<int>>&v){
        int n = v.size();
        if(n == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(v[0][1]);
        for(int i = 1; i<n; i++){
            if(v[i][1]>ans.back()){
                ans.push_back(v[i][1]);
            }
            else{
                int ind = lower_bound(ans.begin(), ans.end(), v[i][1]) - ans.begin();
                ans[ind] = v[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), customSort);
        
        return solve(envelopes);
    }
};