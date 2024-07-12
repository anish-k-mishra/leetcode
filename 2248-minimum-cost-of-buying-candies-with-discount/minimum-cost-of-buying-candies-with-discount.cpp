class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() == 1){
            return cost[0];
        }
        if(cost.size() == 2){
            return cost[0]+cost[1];
        }
        sort(cost.begin(), cost.end());
        int i = cost.size()-1;
        int j = cost.size()-2;
        int free = cost.size()-3;
        int ans = 0;
        while(i>=0){
            if(j>=0){
                ans+= cost[i]+cost[j];
            }
            else{
                ans += cost[i];
            }
            i -= 3;
            j -= 3;
        }
        return ans;
    }
};