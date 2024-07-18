class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = 0, e = k-1;
        double maxi = INT_MIN;
        double sum = 0;
        for(int i = s; i<=e; i++){
            sum += nums[i];
        }
        maxi = max(maxi, sum);
        s++;
        e++;
        while(e<nums.size()){
            sum -= nums[s-1];
            sum += nums[e];
            maxi = max(maxi, sum);
            s++;
            e++;
        }
        return maxi/k;
    }
};