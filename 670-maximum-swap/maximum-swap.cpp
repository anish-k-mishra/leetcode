class Solution {
public:
    int maximumSwap(int num) {
        //converting the num to array
        vector<int>arr;
        int a = num;
        while(a>0){
            int n = a%10;
            a = a/10;
            arr.push_back(n);
        }
        reverse(arr.begin(), arr.end());
        int n = arr.size();

        int maxe = arr[n-1], maxi = n-1, swapid1 = -1, swapid2 = -1;

        for(int i = n-2; i>= 0; i--){
            if(arr[i] > maxe){
                maxe = arr[i];
                maxi = i;
            }
            else if(arr[i] < maxe){
                swapid1 = i;
                swapid2 = maxi;
            }
        }

        //perform swapping
        if(swapid1 != -1){
            swap(arr[swapid1], arr[swapid2]);
        }

        string s = "";
        for(int i = 0; i<n; i++){
            s += to_string(arr[i]);
        }
        return stoi(s);
    }
};