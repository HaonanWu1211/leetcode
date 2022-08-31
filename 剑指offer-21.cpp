class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        int i = 0, j = len-1;
        for(int k = 0; k < len; k++){
            if(nums[k] % 2){
                res[i] = nums[k];
                i++;
            }else{
                res[j] = nums[k];
                j--;
            }
        }
        return res;
    }
};