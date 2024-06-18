class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>v;
        for(int i = 0; i<difficulty.size(); i++){
            pair<int, int>p = make_pair(difficulty[i], profit[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        priority_queue<int>pq;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<worker.size()){
            while(j<v.size() && worker[i] >= v[j].first){

                pq.push(v[j].second);
                j++;
            }
            if(!pq.empty()){
                ans += pq.top();
            }
            i++;
        }
        return ans;
    }
};