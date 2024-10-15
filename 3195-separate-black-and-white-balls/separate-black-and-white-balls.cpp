class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        int j = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '0'){
                cnt+= (i-j);
                j++;
            }
        }
        return cnt;
    }
};