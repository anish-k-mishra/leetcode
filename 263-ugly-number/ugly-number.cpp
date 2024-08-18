class Solution {
public:
    bool isUgly(int n) {
        int num = n;
        if(n == 1 ){
            return true;
        }
        if(n == 0){
            return false;
        }
        vector<int>v = {2, 3, 5};
        for(int i = 0; i<3; i++){
            if(num%v[i] == 0){
                while(num%v[i] == 0){
                    num /= v[i];
                }
            }
        }
        return num == 1;
    }
};