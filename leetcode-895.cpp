class FreqStack {

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        count[val]++;
        group[count[val]].push(val);
        maxFreq = max(maxFreq, count[val]);
    }
    
    int pop() {
        int temp = group[maxFreq].top();
        group[maxFreq].pop();
        count[temp]--;
        if(group[maxFreq].empty())
            maxFreq--;
        return temp;
    }

private:
    int maxFreq;
    map<int, stack<int>> group;
    map<int, int> count;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
