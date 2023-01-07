class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //»¬¶¯´°¿Ú
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = n+1;
        if(sum < x)
            return -1;
        int lsum=0, rsum=sum;
        int right = n, left = -1;
        while(left < n){
            if(left != -1){
                lsum += nums[left];
            }
            while(right >= 0 && lsum + rsum > x){
                rsum -= nums[n-right];
                right--;
            }
            if(lsum + rsum == x){
                res = min(res, left+1+right);
            }
            left++;
        }
        return res>n ? -1 : res; 
    }
};
