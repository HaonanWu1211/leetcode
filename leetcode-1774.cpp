class Solution {
public:
    
    void DFS(vector<int>& toppingCosts, int target, int& cost, int& res, int j){
        if(abs(target-cost) < abs(target-res) || (abs(target-cost) == abs(target-res) && target-cost > 0 && target-res < 0)){
            res = cost;
        }
        if(j == toppingCosts.size() || cost >= target) // terminate condition
            return;
        for(int i = 0; i <= 2; i++){ // two at most
            cost += toppingCosts[j]*i;
            DFS(toppingCosts, target, cost, res, j+1);
            cost -= toppingCosts[j]*i;
        }
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int cost = 0;
        int res = INT_MAX;
        for(int i = 0; i < baseCosts.size(); i++){
            cost = baseCosts[i];
            int j = 0;
            DFS(toppingCosts, target, cost, res, j);
        }
        return res;
    }
};
