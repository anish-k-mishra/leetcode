class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> temp(s.length(), 0);
        for(auto i: shifts){
            int st = i[0];
            int e = i[1];
            int d = i[2];
            if(d == 1){
                temp[st]++;
                if(e+1<temp.size()){
                    temp[e+1]--;
                }
            }
            else{
                temp[st]--;
                if(e+1<temp.size()){
                    temp[e+1]++;
                }
            }
        }

        int cum_sum = 0;
        for(int i = 0; i<temp.size(); i++){
            cum_sum = (cum_sum + temp[i])%26;
            if(cum_sum < 0){
                cum_sum += 26;
            }
            char newChar = (char)('a' + ((s[i]-'a' + cum_sum)%26));
            s[i] = newChar;

        }
        return s;
    }
};