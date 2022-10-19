class Solution {
public: 
    vector<double> DFS(int n){
        if(n == 1)
            return vector<double>{1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6};
        else{
            vector<double> res(5*n+1, 0);
            vector<double> pre = DFS(n-1);
            for(int i = n; i <= 6*n; i++){
                for(int j = max(i-6, n-1); j <= min(i-1, 6*(n-1)); j++){
                    res[i-n] += pre[j-n+1]/6;
                }
            }
            return res;
        }
    }
    vector<double> dicesProbability(int n) {
        return DFS(n);
    }
};