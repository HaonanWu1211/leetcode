class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //利用二叉搜索树的思想
        if(matrix.size() <= 0 || matrix[0].size() <= 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m-1;
        int j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};
