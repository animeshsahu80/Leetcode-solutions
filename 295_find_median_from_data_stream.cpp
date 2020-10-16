class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_h;
    priority_queue<int,vector<int>,greater<int>> min_h;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_h.size()==0 || max_h.top()>=num){
            max_h.push(num);
            if(max_h.size()>min_h.size()+1){
                min_h.push(max_h.top());
                max_h.pop();
            }
        }
        else{
            min_h.push(num);
            if(min_h.size()>max_h.size()+1){
                max_h.push(min_h.top());
                min_h.pop();
            }
        }
    }
    
    double findMedian() {
       
        if (max_h.size() > min_h.size())
            return max_h.top();
        else if (max_h.size() < min_h.size())
            return min_h.top();
         else 
            return 1.0 * ((min_h.top()+ max_h.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */