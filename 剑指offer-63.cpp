class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int day = prices.size();
        if(prices.size() == 0)
            return res;
        int maximum = prices[day-1];
        for(int i = prices.size()-2; i >= 0; i--){
            if(prices[i] < maximum){
                res = max(res, maximum-prices[i]);
            }else{
                maximum = prices[i];
            }
        }
        return res;
    }
};