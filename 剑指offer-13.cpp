// version 1 --- before improvement
class Solution {
public:
    void DFS(int i, int j, int k, int& num, vector<vector<bool>>& visit){
        if(i < 0 || i >= visit.size() || j < 0 || j >= visit[0].size() || visit[i][j] == true)
            return;
        int sum = 0;
        int ii = i, jj = j;
        while(ii > 0){
            sum += (ii % 10);
            ii /= 10;
            if(sum > k)
                return;
        }
        while(jj > 0){
            sum += (jj % 10);
            jj /= 10;
            if(sum > k)
                return;
        }
        visit[i][j] = true; // forget to add it, must pay attention to it next time
        num += 1;
        DFS(i+1, j, k, num, visit);
        DFS(i, j+1, k, num, visit);
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int num = 0;
        DFS(0, 0, k, num, visit);
        return num;
    }
};


// version 2 --- after improvement
// avoid repeated calculations of sum of digits
// remember sum of digits during DFS
class Solution {
public:
    void DFS(int i, int j, int ii, int jj, int m, int n, int k, int& num, vector<vector<bool>>& visit){
        if(i >= m || j >= n || ii+jj > k || visit[i][j] == true)
            return;
        visit[i][j] = true;
        num++;
        DFS(i+1, j, (i+1)%10 == 0 ? (ii-8):(ii+1), jj, m, n, k, num, visit);
        DFS(i, j+1, ii, (j+1)%10 == 0 ? (jj-8):(jj+1), m, n, k, num, visit);
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int num = 0;
        DFS(0, 0, 0, 0, m, n, k, num, visit);
        return num;
    }
};