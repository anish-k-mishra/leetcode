class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                max++;
                min++;
            }
            else if(s[i] == ')'){
                max--;
                min--;
            }
            else{
                min--;
                max++;
            }

            if(min<0){
                min = 0;
            }
            if(max<0){
                return false;
            }
        }
        if(min == 0){
            return true;
        }
        return false;
    }
};