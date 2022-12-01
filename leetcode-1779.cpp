class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dis = INT_MAX;
        int index = -1;
        for(int i = 0; i < points.size(); i++){
            if(x == points[i][0] && abs(y - points[i][1]) < dis){
                dis = abs(y-points[i][1]);
                index = i;
            }
            else if(y == points[i][1] && abs(x - points[i][0]) < dis){
                dis = abs(x-points[i][0]);
                index = i;
            }
        }
        return index;
    }
};
