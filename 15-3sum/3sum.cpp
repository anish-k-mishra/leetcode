class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                cnt++;
            }
        }
        if(cnt == n){
            vector<int>v(3, 0);
            ans.push_back(v);
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                vector<int>v;
                if(nums[i] + nums[j] + nums[k] == 0){
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    s.insert(v);
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};