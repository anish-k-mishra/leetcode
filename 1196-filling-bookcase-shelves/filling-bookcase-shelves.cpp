class Solution {
public:
    int solve(int ind, vector<vector<int>>&books, int wid, vector<int>&dp){
        if(ind>=books.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int width = 0, maxH = INT_MIN, ans = INT_MAX;
        for(int i = ind; i<books.size(); i++){
            width += books[i][0];
            if(width>wid){
                break;
            }
            maxH = max(maxH, books[i][1]);
            ans = min(ans, maxH+solve(i+1, books, wid, dp));
        }
        return dp[ind] = ans;

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size()+1, -1);
        return solve(0, books, shelfWidth, dp);
    }
}; 