class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i<=n/2; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int nonSpecialCount(int l, int r) {
        int cnt = 0;
        for(int i = sqrt(l); i<=sqrt(r); i++){
            if(i == 1){
                continue;
            }
           
            if(isPrime(i)){
                if(i*i>=l && i*i <=r){

                    cnt++;
                }
            }
        }
        return r-l+1 - cnt;
    }
};