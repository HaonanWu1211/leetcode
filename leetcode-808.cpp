# A combination between dynamic programming and probability theory
class Solution {
public:
    double soupServings(int n) {
        n = (n+24) / 25;
        if(n >= 179) // according to the mathmatic expectation, the probability will converge to 1
            return 1.0; // or will exceed the time limit
        vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
        dp[0][0] = 0.5;
        for(int i = 1; i <= n; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = (dp[max(0, i-4)][j] + dp[max(0, i-3)][j-1] + dp[max(0, i-2)][max(0, j-2)] +
                dp[i-1][max(0, j-3)]) / 4;
            }
        }
        return dp[n][n];
    }
};
