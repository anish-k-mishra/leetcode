class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>m;
        for(int i = 0; i<word.size(); i++){
            m[word[i]]++;
        }
        int n = m.size();
        vector<int>freq;
        for(auto i:m){
            freq.push_back(i.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int cnt ;
        int ans = 0;
        for(int i = 0; i<freq.size(); i++){
            // int push;
            if(i<8){
                cnt = 1;
            }
            else if(i>=8 && i<16){
                cnt = 2;
            }
            else if(i>=16 && i<24){
                cnt = 3;
            }
            else {
                cnt = 4;
            }
            ans+= cnt*freq[i];
            

        }
        return ans;
    }
};