class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};