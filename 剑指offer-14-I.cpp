class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], j*max(dp[i-j], i-j));
                // j -- the cope should be cut at least one time
            }
        } 
        return dp[n];
    }
};

// another way
// divide 3 as more as possible
// three situations need to be considered
// n = div * 3 + mod
// mod == 0 pow(3, div)
// mod == 1 2*2*pow(3, div-1)
// mod == 2 2*pow(3, div)
// n <= 3 need to be considered alone