class Solution {
public:
    bool isPresent(string s, vector<string>&v){
        for(int i = 0; i<v.size(); i++){
            if(s == v[i]){
                return true;
            }
        }
        return false;
    }
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int>m;
        set<string> s;
        for(int i = 0; i<message.size(); i++){
            m[message[i]]++;
        }
        // while(!s.empty()){
        //     auto it = s.begin();
        //     m[*it]++;
        //     s.erase(it);
        // }
        for(int i = 0; i<bannedWords.size(); i++){
            s.insert(bannedWords[i]);
        }
        while(!s.empty()){
            auto it = s.begin();
            m[*it]++;
            s.erase(it);
        }
        int cnt = 0;
        for(auto it:m){
            if(it.second == 2 && isPresent(it.first, bannedWords)){
                cnt++;
            }
            if(it.second>2 && isPresent(it.first, bannedWords)){
                return true;
            }
        }
        if(cnt>=2){
            return true;
        }
        return false;
    }
};