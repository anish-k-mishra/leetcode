class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //sliding window approach
        int ans = INT_MIN, win = 0, l = 0;
        for(int r = 0; r<s.length(); r++){
            win += abs(s[r] - t[r]);
            while(win>maxCost){
                win -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;

    }
};