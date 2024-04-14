class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;\
        vector<vector<int>>ansv;
        for(int i = 1; i<=n; i++){
            vector<int>v;
            int ans = 1;
            v.push_back(ans);
            for(int j = 1; j<i; j++){
                ans *= (i-j);
                ans = ans/j;
                v.push_back(ans);
            }
            ansv.push_back(v);
        }
        return ansv;
    }
};