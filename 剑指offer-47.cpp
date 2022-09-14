class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<int> dp;
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0){
                    sum += grid[0][j];
                    dp.push_back(sum);
                }else{
                    dp[j] = grid[i][j] + (j == 0 ? dp[j] : max(dp[j-1], dp[j]));
                }
            }
        }
        return dp[grid[0].size()-1];
    }
};