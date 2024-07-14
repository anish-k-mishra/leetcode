class Solution {
public:
    string getSmallestString(string s) {
        string str = "";
        string mini = s;
        //mini = min(mini, stoi(s));
        for(int i = 0; i<s.length()-1; i++){
            if( ((s[i]-'0')%2 == 0 && (s[i+1]-'0')%2==0) ||  ((s[i]-'0')%2 != 0 && (s[i+1]-'0')%2!=0)) {
                swap(s[i], s[i+1]);
                mini = min(mini, s);
                swap(s[i], s[i+1]);
            }            
        }
        return str+ mini;
    }
};