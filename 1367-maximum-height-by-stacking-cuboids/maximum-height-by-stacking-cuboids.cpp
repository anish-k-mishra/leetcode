class Solution {
public:
    bool check(vector<int>base, vector<int>newB){
        if(newB[0] <= base[0] && newB[1]<= base[1] && newB[2] <= base[2]){
            return true;
        }
        return false;
    }
    int solve(int n, vector<vector<int>>&a){
        vector<int>currR(n+1, 0);
        vector<int>nextR(n+1, 0);
        for(int curr = n-1; curr>= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                //include
                int take = 0;
                if(prev == -1 || check(a[curr], a[prev])){
                    take = a[curr][2] + nextR[curr+1];
                }
                //exclude
                int notTake = 0+nextR[prev+1];
                currR[prev+1] = max(take, notTake);
            }
            nextR = currR;
        }
        return nextR[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
    }

};