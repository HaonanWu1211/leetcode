class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // find the number which equals the above number plus 2
        int i = 0, j = nums.size()-1, mid;
        if(nums[nums.size()-1] == nums.size()-1)
            return nums.size();
        while(i <= j){
            mid = (i+j)>>1;
            int left = mid == 0 ? -1 : nums[mid-1];
            int right = nums[mid];
            if(right - left == 2)
                return right-1;
            else if(nums[mid] == mid)
                i = mid+1;
            else
                j = mid-1;
        }
        return -1;
    }
};