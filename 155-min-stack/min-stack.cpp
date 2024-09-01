class MinStack {
public:
    vector<int>v;
    int mini = INT_MAX;
    MinStack() {
                
    }
    
    void push(int val) {
        v.push_back(val);
        mini = min(mini, val);
    }
    
    void pop() {
        v.pop_back();
        mini = INT_MAX;
        for(int i = 0; i<v.size(); i++){
            mini = min(mini, v[i]);
        }
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */