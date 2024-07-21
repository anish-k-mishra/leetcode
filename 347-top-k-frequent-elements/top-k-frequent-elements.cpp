class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }   
        priority_queue<pair<int, int>>maxHeap;
        for(auto i:m){
            maxHeap.push({i.second, i.first});
        }
        vector<int>v;
        while(k--){
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return v;
    }
};