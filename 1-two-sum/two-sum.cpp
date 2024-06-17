class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int, int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]] = i;
        }

        for(int i = 0; i<nums.size(); i++){
            if(m[target-nums[i]] && m[target - nums[i]] != i){
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                break;

            }
        }
        return v;
    }
};