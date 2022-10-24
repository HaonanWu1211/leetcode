class Solution {
public:
    int cal(int val){
        int res = 0;
        while(val){
            res += val %10;
            val /= 10;
        }
        return res;
    }
    void DFS(int m, int n, int k, int& count, int i, int j, vector<vector<bool>>& visit){
        if(m >= i || n >= j || cal(m) + cal(n) > k || visit[m][n] == true)
            return;
        count++;
        visit[m][n] = true;
        DFS(m+1, n, k, count, i, j, visit);
        DFS(m, n+1, k, count, i, j, visit);
    }
    int movingCount(int m, int n, int k) {
        int count = 0;
        int i = 0, j = 0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        DFS(i, j, k, count, m, n, visit);
        return count;
    }
};