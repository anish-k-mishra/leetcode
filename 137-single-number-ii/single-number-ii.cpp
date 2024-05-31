class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int a;
        for(auto i:m){
            if(i.second == 1){
                a = i.first;
            }
        }
        return a;
    }
};