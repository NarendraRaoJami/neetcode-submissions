class MedianFinder {
public:

    priority_queue<int,vector<int>, greater<int>> min_stack;
    priority_queue<int,vector<int>, less<int>> max_stack;

    MedianFinder() {
        min_stack.push(INT_MAX);
        max_stack.push(INT_MIN);
    }
    
    void addNum(int num) {
        min_stack.push(num);

        int min_ss = min_stack.size();
        int max_ss = max_stack.size();

        if(min_ss == max_ss + 2) {
            int val = min_stack.top();
            min_stack.pop();
            max_stack.push(val);
        }

        if(min_ss >1 && max_ss>1 && min_stack.top() < max_stack.top()) {
            int a = min_stack.top();
            int b = max_stack.top();
            min_stack.pop();
            max_stack.pop();
            min_stack.push(b);
            max_stack.push(a);
        }
    }
    
    double findMedian() {
        int min_ss = min_stack.size();
        int max_ss = max_stack.size();
        
        if ((min_ss + max_ss) & 1) {
            return (double) min_stack.top();
        } else {
            return ((double) min_stack.top() + (double) max_stack.top()) / 2.0;
        }
    }
};
