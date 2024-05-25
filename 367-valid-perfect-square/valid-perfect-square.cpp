class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 1){
            return true;
        }
        if(num == 4){
            return true;
        }
        long long int s = 1;
        long long int e = num;
        long long int mid = s+ (e-s)/2;
        while(s<=e){
            if(mid*mid == num){
                return true;
            }
            if(mid*mid> num){
                e = mid-1;
            }
            if(mid*mid < num){
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};