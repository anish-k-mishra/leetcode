#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;  // The first ugly number is 1
        
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < n; ++i) {
            int nextUgly = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});
            dp[i] = nextUgly;
            
            if (nextUgly == dp[p2] * 2) p2++;
            if (nextUgly == dp[p3] * 3) p3++;
            if (nextUgly == dp[p5] * 5) p5++;
        }
        
        return dp[n - 1];
    }
};
