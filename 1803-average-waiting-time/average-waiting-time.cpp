class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = customers[0][1];
        double fin = customers[0][0] + customers[0][1];
        for(int i = 1; i<customers.size(); i++){
            double wait = 0;
            if(customers[i][0] >= fin){
                wait = customers[i][1];
            }
            else if(customers[i][0] < fin){
                wait = fin - customers[i][0] + customers[i][1];
            }
            ans += wait;
            if(customers[i][0] > fin){
                fin += (customers[i][0] - fin) + customers[i][1];
            }
            else{
                fin += customers[i][1];
            }
        }
        return ans/customers.size();

    }
};