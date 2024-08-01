class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i = 0; i<details.size(); i++){
            string s = details[i];
            string age = s.substr(11, 2);
            int agen = stoi(age);
            // cout<<agen<<endl;
            if(agen>60){
                cnt++;
            }
        }
        return cnt;
    }
};