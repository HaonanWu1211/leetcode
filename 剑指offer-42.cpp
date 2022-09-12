class Solution {
public:
    int maxSubArray(vector<int>& nums) { // dynamic programming
        int maxVal = nums[0]; // dp[i]代表以元素nums[i]为*结尾*的连续子数组最大和
        // use vector nums to represent dp to reduce space complexity to O(1)
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > 0){
                nums[i] = nums[i-1] + nums[i];
            }
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal;
    }
};
