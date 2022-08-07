class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> vec(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            if(vec[nums[i]] != -1){
                return vec[nums[i]];
            }else{
                vec[nums[i]] = nums[i];
            }
        }
        return -1;
    }
};
