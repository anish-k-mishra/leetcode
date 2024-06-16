class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sumFormed = 0;
        long long expSum = 1;
        int ans = 0;
        int i = 0;
        while(sumFormed < n){
            if(sumFormed >= expSum){
                expSum = sumFormed+1;
            }
            else{
                if(i<nums.size() && nums[i] <= expSum){
                    sumFormed += nums[i];
                    i++;
                }
                else{
                    ans++;
                    sumFormed += expSum;
                }
            }
        }
        return ans;
    }
};