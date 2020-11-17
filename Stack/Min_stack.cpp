/*
    Problem->
    https://leetcode.com/problems/min-stack/
    Solution->
    https://www.geeksforgeeks.org/design-a-stack-to-retrieve-original-elements-and-return-the-minimum-element-in-o1-time-and-o1-space/?ref=rp
    
    Note-> This solution works for Max stack as well.
*/

class MinStack {
public:
    long long currMin;
    stack<long long> st;

    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        currMin = INT_MAX;
    }
    
    void push(int x) {
        if(st.empty()){
            st.push(x);
            currMin = x;
            return;
        }
        if(x >= currMin){
            st.push(x);
            return;
        }
        long long encode = (2ll * x) - currMin;
        st.push(encode);
        currMin = x;
    }
    
    void pop() {
        if(st.top() >= currMin){
            st.pop();
            return;
        }
        currMin = (2ll * currMin) - st.top();
        st.pop();
        return;
    }
    
    int top() {
        if(st.top() >= currMin)
            return (int)st.top();
        
        /*
            can be replaced to return currMin
        */
        long long min_val = (2ll * currMin) - st.top();
        int recover = (min_val + st.top())/2;
        return recover; 
    }
    
    int getMin() {
        return (int)currMin;
    }
};