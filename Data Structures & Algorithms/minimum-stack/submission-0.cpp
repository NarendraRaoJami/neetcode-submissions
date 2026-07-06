class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        int mini = st.top();
        while(!st.empty()){
            mini = min(mini,st.top());
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return mini;
    }
};
