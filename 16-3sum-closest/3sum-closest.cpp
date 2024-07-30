class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mind = INT_MAX;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                cnt++;
            }
        }
        if(cnt == nums.size()){
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int addn = nums[i]+nums[j]+nums[k];
                if(addn == target){
                    return target;
                }
                else{
                    int a = mind;
                    mind = min(mind, abs(target-addn));
                    if(a != mind){
                        ans = addn;
                    }
                    if(addn>target){
                        k--;
                    }
                    if(addn<target){
                        j++;
                    }
                }
                
            }
        }
        return ans;
    }
};