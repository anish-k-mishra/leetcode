class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v = heights;
        // for(int i = 0; i<heights.size(); i++){
        //     v.push_back(heights[i]);
        // }
        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i = 0; i<v.size(); i++){
            if(v[i] != heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};