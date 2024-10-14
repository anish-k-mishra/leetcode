class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int>pq;
        for(int i = 0; i<nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k--){
            int a = pq.top();
            pq.pop();
            sum+= a;
            a = (int)ceil(a/3.0);
            pq.push(a);
        }

        return sum;
    }
};