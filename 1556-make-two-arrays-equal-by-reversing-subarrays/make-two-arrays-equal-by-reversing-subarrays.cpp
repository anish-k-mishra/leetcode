class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>m;
        for(int i = 0; i<target.size(); i++){
            m[target[i]]++;
        }
        for(int i = 0; i<target.size(); i++){
            if(m[arr[i]] != 0){
                m[arr[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};