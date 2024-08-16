class Solution {
public:
    void solve(int num, unordered_map<int, string>&m, string& ans){
        if(m.count(num)){
            ans += m[num];
            return;
        }
        if(num>1000){
            int n = num/1000;
            while(n--){
                ans+=m[1000];
            }
            num = num%1000;
            solve(num, m, ans);
        }
        else if(num>900){
            int n = num/900;
            while(n--){
                ans += m[900];
            }
            num = num%900;
            solve(num, m, ans);
        }
        else if(num>500){
            int n = num/500;
            while(n--){
                ans+= m[500];
            }
            num = num%500;
            solve(num, m, ans);
        }
        else if(num>400){
            int n = num/400;
            while(n--){
                ans+= m[400];
            }
            num = num%400;
            solve(num, m, ans);
        }
        else if(num>100){
            int n = num/100;
            while(n--){
                ans+=m[100];
            }
            num = num%100;
            solve(num, m, ans);
        }
        else if(num>90){
            int n = num/90;
            while(n--){
                ans += m[90];
            }
            num = num%90;
            solve(num, m, ans);
        }
        else if(num>50){
            int n = num/50;
            while(n--){
                ans += m[50];
            }
            num = num%50;
            solve(num, m, ans);
        }
        else if(num>40){
            int n = num/40;
            while(n--){
                ans += m[40];
            }
            num = num%40;
            solve(num, m, ans);
        }
        else if(num>10){
            int n = num/10;
            while(n--){
                ans += m[10];
            }
            num = num%10;
            solve(num, m, ans);
        }
        else if(num>5){
            int n = num/5;
            while(n--){
                ans += m[5];
            }
            num = num%5;
            solve(num, m, ans);
        }
        else if(num>4){
            int n = num/4;
            while(n--){
                ans += m[4];
            }
            num = num%4;
            solve(num, m, ans);
        }
        else if(num>=1){
            int n = num;
            while(n--){
                ans += m[1];
            }
        }
        
    }
    string intToRoman(int num) {
        unordered_map<int, string>m = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        string ans = "";
        solve(num, m, ans);
        return ans;
        
    }
};