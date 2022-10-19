// no-repeated && max-min<5 --> isStraight
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = 0;
        int i = 0;
        while(nums[i] == 0){
            i++;
            num++;
        }
        i++;
        while(i < 5){
            if(nums[i] == nums[i-1])
                return false;
            if(nums[i]-nums[i-1] > 1){
                num -= (nums[i]-nums[i-1]-1);
                if(num < 0)
                    return false;
            }
            i++;
        }
        return true;
    }
};