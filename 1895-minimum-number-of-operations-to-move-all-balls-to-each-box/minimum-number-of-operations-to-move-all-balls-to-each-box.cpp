class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>left(n, 0);
        vector<int>right(n, 0);
        vector<int>res(n);

        int cntl = boxes[0]-'0';
        int cntr = boxes[n-1]-'0';
        for(int i = 1; i<n; i++){
            left[i] = left[i-1]+cntl;
            cntl += boxes[i]-'0';

            right[n-1-i] = right[n-1-i+1] + cntr;
            cntr += boxes[n-1-i] - '0';
        }

        for(int i = 0; i<n; i++){
            res[i] = left[i]+right[i];
        }
        return res;
    }
};