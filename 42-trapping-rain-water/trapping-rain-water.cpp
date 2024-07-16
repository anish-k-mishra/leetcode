class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2){
            return 0;
        }
        long long int ans = 0;
        int l = 0, r = height.size()-1, leftmax = 0, rightmax = 0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]<leftmax){
                    ans+= leftmax-height[l];
                }
                else{
                    leftmax = height[l];
                }
                l++;
            }
            else{
                if(height[r]<rightmax){
                    ans+= rightmax-height[r];
                }
                else{
                    rightmax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};