class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> neg(n+1);
        vector<long long> W(n+1);
        deque<int> dq = {0};
        vector<int> f(n+1), g(n+1);
        for(int i = 1; i <= n; i++){
            if(i > 1){
                neg[i] = neg[i-1] + (boxes[i-1][0]!=boxes[i-2][0]);
            }
            W[i] = W[i-1] + boxes[i-1][1];
        }
        for(int i = 1; i <= n; i++){
            while(i - dq.front() > maxBoxes || W[i]-W[dq.front()] > maxWeight){
                dq.pop_front();
            }
            f[i] = g[dq.front()] + neg[i] + 2;
            if(i != n){
                g[i] = f[i] - neg[i+1];
                while(!dq.empty() && g[dq.back()] >= g[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        return f[n];
    }
};
