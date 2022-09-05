class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MinStack() {
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }else{
            int temp = s2.top();
            if(temp >= x){
                s2.push(x);
            }
        }
    }
    
    void pop() {
        if(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            if(s2.top() == temp){
                s2.pop();
            }
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */