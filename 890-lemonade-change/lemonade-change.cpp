class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int>m;
        if(bills[0]>5){
            return false;
        }
        for(int i = 0; i<bills.size(); i++){
            m[bills[i]]++;
            if(bills[i] == 10){
                if(m[5] != 0){
                    m[5]--;
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(bills[i] == 20){
                if(m[10]>=1 && m[5]>=1){
                    m[10]--;
                    m[5]--;
                    continue;
                }
                else if(m[5]>=3){
                    m[5] -= 3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};