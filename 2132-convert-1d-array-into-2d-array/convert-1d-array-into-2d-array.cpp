class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>v;
        if(m*n != original.size()){
            return v;
        }

        for(int i = 0; i<original.size(); i+=n){
            int cnt = 0;
            vector<int>temp;
            for(int j = i; j<original.size() && cnt<n; j++, cnt++){
                temp.push_back(original[j]);
            }
            v.push_back(temp);
        }

        return v;
    }
};