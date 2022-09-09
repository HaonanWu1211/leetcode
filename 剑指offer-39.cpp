// Way1 -- 排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// Way2 -- 摩尔投票法 空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, vote;
        for(int i = 0; i < nums.size(); i++){
            if(num == 0) vote = nums[i];
            num += vote == nums[i] ? 1 : -1;
        }
        return vote;
    }
};