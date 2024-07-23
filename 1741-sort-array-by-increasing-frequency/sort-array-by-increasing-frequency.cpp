class Solution {
public:
    static bool comparator(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.first == b.first) {
            // If first elements are equal, sort by second element in descending order
            return a.second > b.second;
        }
        // Otherwise, sort by first element in ascending order
        return a.first < b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>>v;
        for(auto i:m){
            v.push_back({i.second, i.first});
        }

        sort(v.begin(), v.end(), comparator);

        vector<int>ans;
        for(int i = 0; i<v.size(); i++){
            int a = v[i].first;
            while(a--){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};