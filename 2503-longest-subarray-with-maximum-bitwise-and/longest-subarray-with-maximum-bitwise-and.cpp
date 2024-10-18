class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        int maxim=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                while(i<nums.size() && nums[i]==maxi){
                    cnt++;
                    i++;

                }
                
                
            }
            maxim=max(maxim,cnt);
                cnt=0;
        }
        if(maxim==0){
            return 1;
        }
        return maxim;
        
    }
};