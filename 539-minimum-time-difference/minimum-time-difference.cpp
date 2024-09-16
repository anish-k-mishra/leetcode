class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v;
        int n = timePoints.size();
        for(int i = 0; i<timePoints.size(); i++){
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3, 2));
            int a = 60*h + m;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for(int i = 1; i<v.size(); i++){
            ans = min(ans, v[i]-v[i-1]);
        }

        ans = min(ans, (60*24 - v[n-1] + v[0]));
        return ans;
    }
};