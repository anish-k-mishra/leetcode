class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int a = x;
        vector<int> v;
        while(a>0){
            int b = a%10;
            v.push_back(b);
            a = a/10;

        }
        int i = 0;
        int j = v.size()-1;
        while(i<=j){
            if(v[i] != v[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};