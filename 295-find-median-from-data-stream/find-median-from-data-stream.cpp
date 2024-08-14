class MedianFinder {
public:
    priority_queue<int>mxh;
    priority_queue<int, vector<int>, greater<int>>mnh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxh.push(num);
        mnh.push(mxh.top());
        mxh.pop();

        if(mxh.size()<mnh.size()){
            mxh.push(mnh.top());
            mnh.pop();
        }
        
    }
    
    double findMedian() {
        if(mxh.size()>mnh.size()){
            return mxh.top();
        }
        else{
            return (double)(mxh.top()+mnh.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */