class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(1);
        int a = 0, b = 0, c = 0;
        for(int i = 2; i <= n; i++){
            dp.push_back(min(dp[a]*2, min(dp[b]*3, dp[c]*5)));
            if(dp[a]*2 == dp[i-1])
                a++;
            if(dp[b]*3 == dp[i-1])
                b++;
            if(dp[c]*5 == dp[i-1])
                c++;
        }
        return dp[n-1];
    }
};