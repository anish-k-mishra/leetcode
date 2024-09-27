class MyCalendarTwo {
public:
    map<int, int> timeline;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        timeline[start]++;
        timeline[end]--;
        
        int ongoingEvents = 0;
        
        for (auto it : timeline) {
            ongoingEvents += it.second;
            if (ongoingEvents >= 3) {
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }
        return true;
    }
};
