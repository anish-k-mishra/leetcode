class Solution {
public:
    int solve(int cnt, int curr, int n){
        if(cnt == n){
            return 0;
        }
        if(cnt>n){
            return 1000;
        }

        //paste
        int res1 = 1+ solve(cnt+curr, curr, n);

        //copy+paste;
        int res2 = 2+ solve(cnt+cnt, cnt, n);

        return min(res1, res2);
    }
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        return 1+ solve(1, 1, n);
    }
};