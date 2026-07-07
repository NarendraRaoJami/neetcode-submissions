class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>> min_heap;
    priority_queue<int,vector<int>,greater<int>> max_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        if(!max_heap.empty() && min_heap.top() > max_heap.top()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if(min_heap.size() > max_heap.size() + 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            return (max_heap.top() + min_heap.top())/2.0;
        }
        else if(min_heap.size() > max_heap.size()){
            return min_heap.top();
        }
        else{
            return max_heap.top();
        }
    }
};
