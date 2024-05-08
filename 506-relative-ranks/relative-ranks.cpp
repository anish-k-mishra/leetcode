class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // vector<int> v = score;
        // sort(v.begin(), v.end());
        int n = score.size();
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            pq.push(score[i]);
        }
        unordered_map<int, int>m;
        for(int i = 0; i<n; i++){
            m[score[i]] = i;
        }
        vector<string>v(n);
        int cnt = 1;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            int index = m[top];
            if(cnt == 1){
                v[index] = "Gold Medal";
            }
            else if(cnt == 2){
                v[index] = "Silver Medal";
            }
            else if(cnt == 3){
                v[index] = "Bronze Medal";
            }
            else{
                v[index] = to_string(cnt);
            }
            cnt++;
                     

        }
        return v;

    }
};