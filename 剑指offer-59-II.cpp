class MaxQueue {
public:
    queue<int> q;
    deque<int> extra;
    
    MaxQueue() {
    }
    
    int max_value() {
        if(extra.empty())
            return -1;
        return extra.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!extra.empty() && extra.back() < value){
            extra.pop_back();
        }
        extra.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }
        else{
            int element = q.front();
            q.pop();
            if(extra.front() == element)
                extra.pop_front();
            return element;
        }
    }
};