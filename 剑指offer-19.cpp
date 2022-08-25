// recursive solution
class Solution {
public:
    void DFS(string s, string p, int i, int j, int m, int n, bool& flag){
        if(flag)
            return;
        if(j < n-1 && p[j+1] == '*'){
            DFS(s, p, i, j+2, m, n, flag); // 0 times
            // ".*" means each character is random
            while(i < m && (p[j] == '.' || s[i] == p[j])){ // 1-N times
                i++;
                DFS(s, p, i, j+2, m, n, flag);
            }
        }
        else{
            if(i == m && j == n){
                flag = true;
                return;
            }
            else if(i == m || j == n)
                return;
            else{
                if(s[i] == p[j] || p[j] == '.')
                    DFS(s, p, i+1, j+1, m, n, flag);
            }
        }
    } 
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.length(), n = p.length();
        bool flag = false;
        DFS(s, p, i, j, m, n, flag);
        return flag;
    }
};

// dynamic programming solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '*'){
                    if(i == 0 || (p[j-2] != '.' && (s[i-1] != p[j-2])))
                        dp[i][j] = dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2] || dp[i-1][j]; 
                }
                else{
                    if(i != 0)
                        if(p[j-1] == '.' || s[i-1] == p[j-1]){
                            dp[i][j] = dp[i-1][j-1];
                        }
                }
            }
        }
        return dp[m][n];
    }
};