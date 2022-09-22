// 字符串匹配多考虑用动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if(m * n == 0)
            return m+n;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m+1; i++)
            dp[i][0] = i;
        for(int j = 1; j < n+1; j++)
            dp[0][j] = j;
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, word1[i-1] == word2[j-1] ? dp[i-1][j-1] : (dp[i-1][j-1]+1)));
                // 三种情况中的最小值
                // 匹配 abcdef 与 cba
                // 若 abcde 与 cba 编辑距离为 d
                // abcdef 与 cba 编辑距离不会超过 d+1 // 对应左串的一次插入过程
                // 若 abcdef 与 cb 编辑距离为 d
                // abcdef 与 cba 编辑距离不会超过 d+1 // 对应右串的一次插入过程 (左串的一次删除过程,两者是等价的)
                // 若 abcde 与 cb 编辑距离为 d
                // abcdef 与 cba 编辑距离 不会超过 d('f'与'a'相等) 或 d+1('f'与'a'不等) // 对应左串的一次修改过程(可能不需要)
            }
        }
        return dp[m][n];
    }
};