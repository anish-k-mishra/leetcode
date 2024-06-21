class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        if(customers.size() == 1){
            return customers[0];
        }
        int ans = 0;
        for(int i = 0; i<customers.size(); i++){
            if(grumpy[i] == 0){
                ans += customers[i];
                customers[i] = 0;
            }
        }
        int sub = 0;
        int s = 0;
        int e = s + minutes -1;
        while(e < customers.size()){
            int t = 0;
            for(int i = s; i<= e; i++){
                t += customers[i];
            }
            sub = max(sub, t);
            s++;
            e++;
        }
        return ans+sub;
    }
};