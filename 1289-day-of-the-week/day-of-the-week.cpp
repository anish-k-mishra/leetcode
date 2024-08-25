class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        unordered_map<int, string>m = {
            {1, "Sunday"},
            {2, "Monday"},
            {3, "Tuesday"},
            {4, "Wednesday"},
            {5, "Thursday"},
            {6, "Friday"},
            {0, "Saturday"},
        };
        if(month == 1 || month == 2){
            month += 12;
            year -= 1;
        }
        int yoc = year%100;
        int cen =year/ 100;
        int dec = month;

        int weekday = (day+(13*(dec+1)/5) + yoc+(yoc/4)+(cen/4)-(2*cen))%7;
        if (weekday < 0) {
            weekday += 7;
        }
        return m[weekday];
    }
};