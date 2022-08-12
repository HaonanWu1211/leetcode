// DFS + 剪枝
class Solution {
public:
    void DFS(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int i, int j, int k, bool& result){
        if(result || i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visit[i][j] == true)
            return;
        if(board[i][j] == word[k]){
            if(k == word.length()-1){
                result = true;
                return;
            }else{
                visit[i][j] = true;
                DFS(board, word, visit, i+1, j, k+1, result);
                DFS(board, word, visit, i, j+1, k+1, result);
                DFS(board, word, visit, i-1, j, k+1, result);
                DFS(board, word, visit, i, j-1, k+1, result);
                visit[i][j] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0){
            return false;
        }
        int m = board.size(), n = board[0].size(), len = word.length();
        int k = 0;
        bool result = false;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                DFS(board, word, visit, i, j, k, result);
                if(result)
                    return true;
            }
        }
        return false;
    }
};