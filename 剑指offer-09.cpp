class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty() && s2.empty())
            return -1;
        if(s2.empty()){
            while(!s1.empty()){
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
};