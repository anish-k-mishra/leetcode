class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //no of groups = max no. of overlapping intervals overall
        int maxi = INT_MIN;
        for(auto i : intervals){
            maxi = max(maxi, i[1]);
        }
        vector<int>v(maxi+2, 0);
        for(auto i: intervals){
            v[i[0]]+=1;
            v[i[1]+1]-=1;
        }

        //finding prefix sum and storing the max prefix sum
        int ans = INT_MIN;
        for(int i = 1; i<v.size(); i++){
            v[i] = v[i-1]+v[i];
            ans = max(ans, v[i]);
        }
        return ans;
    }
};