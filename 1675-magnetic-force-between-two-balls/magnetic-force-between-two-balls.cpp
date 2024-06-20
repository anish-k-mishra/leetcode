class Solution {
public:
    bool isAllocPoss(int mid, vector<int>&pos, int m){
        int ballPlaced = 1;
        int lastPos = pos[0];
        for(int i = 1; i<pos.size(); i++){
            if(pos[i] - lastPos >= mid){
                ballPlaced++;
                lastPos = pos[i];
            }
            if(ballPlaced >= m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        if(m>position.size()){
            return -1;
        }
        int n = position.size();
        sort(position.begin(), position.end());
        int s = 1;
        int e = position[n-1] - position[0];
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isAllocPoss(mid, position, m)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};