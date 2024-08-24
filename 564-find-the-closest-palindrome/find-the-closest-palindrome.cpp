class Solution {
private: 
    long long solve(long long f, bool isOdd){
        long long ans = f;
        if(isOdd){
            f/=10;
        }
        while(f>0){
            ans = ans*10 + (f%10);
            f /= 10;
        }
        return ans;
    }
public:
    string nearestPalindromic(string n) {
        vector<long long>v;
        int len = n.length();
        bool isOdd = (len%2 != 0);

        int mid = (len%2 == 0) ? (len/2) : (len/2 +1);
        long long firstHf = stoll(n.substr(0, mid));
        v.push_back(solve(firstHf, isOdd));
        v.push_back(solve(firstHf+1, isOdd));
        v.push_back(solve(firstHf-1, isOdd));
        v.push_back((long long)pow(10, len-1)-1); // all 9s
        v.push_back((long long)pow(10, len)+1); //101, 1001, 10001...

        long long num = stoll(n); 
        long long minDif = LLONG_MAX;
        long long ans = LLONG_MAX;

        for(auto i:v){
            if(i == num){
                continue;
            }
            long long curDif = abs(i-num);
            if(curDif<minDif){
                ans = i;
                minDif = curDif;
            }
            else if(curDif == minDif){
                ans = min(ans, i);
            }
        }
        return to_string(ans);
    }
};