class Solution {
public:
    int maxSubArray(vector<int>& nums) { // dynamic programming
        int maxVal = nums[0]; // dp[i]������Ԫ��nums[i]Ϊ*��β*����������������
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
