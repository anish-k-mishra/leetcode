class Solution {
public:
    int minOperations(vector<string>& logs) {
        int state = 0;
        for(int i = 0; i<logs.size(); i++){
            if(state == 0 && logs[i] == "../"){
                continue;
            }
            else if(logs[i] == "./"){
                continue;
            }
            else if(state != 0 && logs[i] == "../"){
                state--;
            }
            else{
                state++;
            }
        }
        return state;
    }
};