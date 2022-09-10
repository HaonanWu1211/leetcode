// priority_queue
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> res;
        if(k == 0)
            return res;
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++){
            if(pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// quick sort
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        QuickSort(arr, k, 0, arr.size()-1);
        return vector<int>(arr.begin(), arr.begin()+k);
    }
    void QuickSort(vector<int>& arr, int k, int l, int r){
        if(l >= r)
            return;
        int num = arr[l];
        int ll = l, rr = r;
        while(ll < rr){
            while(ll < rr && arr[rr] >= num) rr--;
            arr[ll] = arr[rr];
            while(ll < rr && arr[ll] <= num) ll++;
            arr[rr] = arr[ll]; 
        }
        arr[ll] = num;
        if(ll > k-1) QuickSort(arr, k, l, ll-1);
        if(ll < k-1) QuickSort(arr, k, ll+1, r);
    }
};
