class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        while(n>0){
            v.push_back(n%10);
            n = n/10;
        }
        reverse(v.begin(), v.end());
        int ind = -1;
        for(int i = v.size()-2; i>=0; i--){
            if(v[i]<v[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            return -1;
        }
        for(int i = v.size()-1; i>ind; i--){
            if(v[i]>v[ind]){
                swap(v[i], v[ind]);
                break;
            }
        }

        reverse(v.begin()+ind+1, v.end());
        long long num = 0;
        for(int i = v.size()-1; i>=0; i--){
            num += v[i]*pow(10,v.size()-1-i);
        }
        if(num > INT_MAX){
            return -1;
        }
        return num;
    }
};