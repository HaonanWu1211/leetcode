class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(nums[left] + nums[right] != target){
            if(nums[left] + nums[right] > target){
                right--;
            }else{
                left++;
            }
        }
        return vector<int>{nums[left], nums[right]};
    }
};
