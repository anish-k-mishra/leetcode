class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>v;
        for(auto i:queries){
            int a = 0;
            for(int j = i[0]; j<=i[1]; j++){
                a = a^arr[j];
            }
            v.push_back(a);
        }
        return v;
    }
};