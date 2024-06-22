class Solution {
public:
    int solve(vector<int>& v, int k){
        if(k<0){
            return 0;
        }
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r<v.size()){
            sum += v[r];
            while(sum>k){
                sum -= v[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
       return solve(nums, k) - solve(nums, k-1); 
    }
};