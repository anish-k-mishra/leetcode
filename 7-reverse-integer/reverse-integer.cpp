class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x<0){
            neg = true;
        }
        x = abs(x);
        stack<int>s;
        while(x>0){
            int n = x%10;
            s.push(n);
            x = x/10;
        }
        long long ans = 0;
        int i = 0;
        while(!s.empty()){
            int n = s.top();
            s.pop();
            ans += n*pow(10,i);
            i++;
        }
        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }
        if(neg){
            return -ans;
        }
        return ans;
    }
};