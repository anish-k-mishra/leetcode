class Solution {
public:
    int solve(int n, vector<int>&days, vector<int>& costs, int index){
        if(index >= n){
            return 0;
        }

        //1day pass
        int opt1 = costs[0] + solve(n, days, costs, index+1);

        //7days pass
        int i;
        for(i = index; i<n && days[i]<days[index]+7; i++);
        int opt2 = costs[1]+solve(n, days, costs, i);

        //30 days pass
        for(i = index; i<n && days[i]<days[index]+30; i++);
        int opt3 = costs[2] + solve(n, days, costs, i);

        return min(opt1, min(opt2, opt3));
    }

    int solveMem(int n, vector<int>&days, vector<int>& costs, int index, vector<int>& dp){
        if(index >= n){
            return 0;
        }

        //step3
        if(dp[index] != -1){
            return dp[index];
        }

        //1day pass
        int opt1 = costs[0] + solveMem(n, days, costs, index+1, dp);

        //7days pass
        int i;
        for(i = index; i<n && days[i]<days[index]+7; i++);
        int opt2 = costs[1]+solveMem(n, days, costs, i, dp);

        //30 days pass
        for(i = index; i<n && days[i]<days[index]+30; i++);
        int opt3 = costs[2] + solveMem(n, days, costs, i, dp);

        dp[index] = min(opt1, min(opt2, opt3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solveMem(n, days, costs, 0, dp);
    }
};