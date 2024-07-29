class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0,n=rating.size();
        for(int i=1; i<n; i++){
            int ls,lg,rs,rg;
            ls = lg = rs = rg = 0;
            for(int j=0; j<i; j++){
                if(rating[j] < rating[i]) ls++;
                else lg++;
            }
            for(int j=i+1; j<n; j++){
                if(rating[j] < rating[i]) rs++;
                else rg++;
            }
            res += (ls*rg) + (rs*lg);
        }
        return res;
    }
};