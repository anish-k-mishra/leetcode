#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                // If the number is even, divide by 2 (remove the last '0')
                s.pop_back();
            } else {
                // If the number is odd, add 1
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            steps++;
        }
        return steps;
    }
};
