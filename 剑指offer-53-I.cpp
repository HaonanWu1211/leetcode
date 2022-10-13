class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        int index = -1;
        int res = 0;
        while(i <= j){
            int mid = (i+j) >> 1;
            if(nums[mid] == target){
                index = mid;
                break;
            }
            else if(nums[mid] < target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        if(index != -1){
            res = 1;
            int offset=1;
            while(index + offset < nums.size() && nums[offset+index] == target){
                res++;
                offset++;
            }
            offset=1;
            while(index - offset >= 0 && nums[index-offset] == target){
                res++;
                offset++;
            }
        }
        return res;
    }
};