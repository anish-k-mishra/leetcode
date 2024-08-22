class Solution {
public:
    int findComplement(int num) {
        int len = (int)log2(num) + 1;
        long long n = (1U<<len) - 1;
        return n^num;
    }
};