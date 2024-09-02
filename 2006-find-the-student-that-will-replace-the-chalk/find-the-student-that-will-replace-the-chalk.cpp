class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int a = k;
        long long tot = 0;
        for(int i = 0; i<chalk.size(); i++){
            tot += chalk[i];
        }
        a = a%tot;

        for(int i = 0; i<chalk.size(); i++){
            if(a<chalk[i]){
                return i;
            }
            a -= chalk[i];
        }
        return -1;
    }
};