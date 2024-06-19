class Solution {
public:
    bool isPossible(int mid, int m, int k, vector<int>&v){
        int tot = 0;
        int cnt = 0;
        for(int i = 0; i<v.size(); i++){
            if(v[i] <= mid){
                cnt++;
            }
            else{
                cnt = 0;
            }
            if(cnt == k){
                tot++;
                cnt = 0;
            }
            if(tot>=m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()){
            return -1;
        }
        int s = INT_MAX;
        int e = INT_MIN;
        int ans = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            s = min(s, bloomDay[i]);
            e = max(e, bloomDay[i]);
        }
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(mid, m, k, bloomDay)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }

        }
        return ans;
    }
};