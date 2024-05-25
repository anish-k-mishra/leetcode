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
    int solveTab(int n, vector<int>& days, vector<int>&costs){
        vector<int>dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int i = n-1; i>=0; i--){
            //1day pass
            int opt1 = costs[0] + dp[i+1];

            //7days pass
            int k;
            for(k = i; k<n && days[k]<days[i]+7; k++);
            int opt2 = costs[1] + dp[k];

            //30 days pass
            for(k = i; k<n && days[k]<days[i]+30; k++);
            int opt3 = costs[2] + dp[k];

            dp[i] = min(opt1, min(opt2, opt3));
        }
        return dp[0];

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        //return solve(n, days, costs, 0);
        return solveMem(n, days, costs, 0, dp);
        //return solveTab(n, days, costs);
    }
};