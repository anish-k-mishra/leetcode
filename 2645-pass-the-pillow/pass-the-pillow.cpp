class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        bool right = true;
        while(time--){
            if(right == true){
                i++;
            }
            if(right == false){
                i--;
            }
            if(i == n || i == 1){
                right = !right;
            }
        }
        return i;
    }
};