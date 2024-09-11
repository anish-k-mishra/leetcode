class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start^goal;
        int cnt = 0;
        while(a>0){
            a = a&(a-1);
            cnt++;
        }
        return cnt;
    }
};