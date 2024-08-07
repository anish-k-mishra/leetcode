class Solution {
public:
    vector<string> tens = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> twentys = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> hundreds = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        if(num<10){
            return tens[num];
        }
        if(num<20){
            return twentys[num-10];
        }
        if(num<100){
            return hundreds[num/10] + (num%10 != 0? " "+tens[num%10]:"");
        }
        if(num<1000){
            return tens[num/100] + " Hundred" + (num%100 != 0? " "+numberToWords(num%100):"");
        }
        if(num<1000000){
            return numberToWords(num/1000) + " Thousand" + (num%1000!=0?" "+numberToWords(num%1000):"");
        }
        if(num<1000000000){
            return numberToWords(num/1000000)+ " Million"+(num%1000000 != 0?" "+numberToWords(num%1000000):"");
        }
        return numberToWords(num/1000000000) + " Billion"+(num%1000000000!=0?" "+numberToWords(num%1000000000):"");
    }
};