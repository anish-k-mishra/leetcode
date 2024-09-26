class MyCalendar {
public:
    map<int, int> m;

    MyCalendar() {
        
    }

    bool book(int start, int end) {
        if (!m.empty()) {
            auto it = m.lower_bound(end);

           
            if (it != m.begin()) {
                --it;
                
                if (it->second > start) {
                    return false;
                }
            }

            
            m[start] = end;
            return true;
        } else {
            m[start] = end;
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */