class Solution {
public:
const int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i = 0; i<nums.size(); i++){
            int s = 0;
            for(int j = i; j<n; j++){
                s= (s+nums[j])%mod;
                v.push_back(s);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = left-1; i<right; i++){
            ans= (ans+v[i])%mod;
        }
        return ans;
    }
};