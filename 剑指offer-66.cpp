class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        // O(2*N)
        int n = a.size();
        vector<int> res(n, 1);
        int temp = 1;
        if(n == 0){
            return res;
        }
        for(int i = 1; i < n; i++){
            temp *= a[i-1];
            res[i] *= temp;
        }
        temp = 1;
        for(int i = n-2; i >= 0; i--){
            temp *= a[i+1];
            res[i] *= temp;
        }
        return res;
    }
};