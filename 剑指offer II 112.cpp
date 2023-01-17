class Solution {

public:
    vector<vector<int>> diret = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& mark, int i, int j, int pre){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()){
            return 0;
        }
        if(pre >= matrix[i][j])
            return 0;
        if(mark[i][j] != 0) 
            return mark[i][j];
        int ans = 0;
        for(int k = 0; k < 4; k++){
            ans = max(ans, DFS(matrix, mark, i+diret[k][0], j+diret[k][1], matrix[i][j]));
        }
        mark[i][j] = 1+ans;
        return mark[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        vector<vector<int>> mark(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                res = max(res, DFS(matrix, mark, i, j, -1));
            }
        }
        return res;
    }

};
