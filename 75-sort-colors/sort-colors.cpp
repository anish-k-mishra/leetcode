class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        map<int, int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        nums = {};
        for(auto i : m){
            for(int k = 0; k<i.second; k++){
                nums.push_back(i.first);
            }
        }

        
    }
};