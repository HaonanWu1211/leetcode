class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return res;
        }
        int tl_x = 0, tl_y = 0;
        int br_x = matrix[0].size()-1, br_y = matrix.size()-1;
        while(tl_x <= br_x && tl_y <= br_y){
            if(tl_x <= br_x){
                for(int i = tl_x; i <= br_x; i++){
                    res.push_back(matrix[tl_y][i]);
                }
            }
            if(tl_y + 1<= br_y){
                for(int i = tl_y+1; i <= br_y; i++){
                    res.push_back(matrix[i][br_x]);
                }
            }
            if(tl_x + 1<= br_x && tl_y + 1 <= br_y){
                for(int i = br_x-1; i >= tl_x; i--){
                    res.push_back(matrix[br_y][i]);
                }
            }
            if(tl_y + 2 <= br_y && tl_x + 1 <= br_x){
                for(int i = br_y - 1; i >= tl_y + 1; i--){
                    res.push_back(matrix[i][tl_x]);
                }
            }
            tl_x++;
            tl_y++;
            br_x--;
            br_y--;
        }
        return res;
    }
};
