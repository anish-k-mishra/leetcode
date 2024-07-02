class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m1;
        unordered_map<int, int>m2;
        vector<int>ans;
        for(int i = 0; i<nums1.size(); i++){
            m1[nums1[i]]++;
        }
        for(int i = 0; i<nums2.size(); i++){
            m2[nums2[i]]++;
        }
        for(auto i:m1){
            if(m2[i.first] != 0 ){
                int a = min(i.second, m2[i.first]);
                while(a--){
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};