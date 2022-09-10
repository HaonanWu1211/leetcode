class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> pq1; // save half biggest numbers
    priority_queue<int> pq2; // save half smallest numbers
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(pq1.size() == pq2.size()){
            pq2.push(num);
            pq1.push(pq2.top());
            pq2.pop();
        }else{
            pq1.push(num);
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        double res;
        if((pq1.size() + pq2.size())%2){
            res = 1.0 * pq1.top();
        }
        else{
            int num1 = pq1.top();
            int num2 = pq2.top();
            res = 1.0 * (num1 + num2) / 2;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
