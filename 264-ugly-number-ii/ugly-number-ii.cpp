class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v(n);
        v[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for(int i = 1; i<n; i++){
            int nxtUgly = min(v[p2]*2, min(v[p3]*3, v[p5]*5));
            v[i] = nxtUgly;

            if(nxtUgly == v[p2]*2){
                p2++;
            }
            if(nxtUgly == v[p3]*3){
                p3++;
            }
            if(nxtUgly == v[p5]*5){
                p5++;
            }

        }
        return v[n-1];
    }
};