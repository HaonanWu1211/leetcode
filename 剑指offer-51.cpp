class Solution { // count the reverse pairs during the merge sort process
public:
        int merge(vector<int>& nums, vector<int>& temp, int i, int j){
            if(i >= j)
                return 0;
            int mid = (i + j) >> 1;
            int res = merge(nums, temp, i, mid) + merge(nums, temp, mid+1, j);
            int m = i, n = mid+1, l = i;
            for(int k = i; k <= j; k++){
                temp[k] = nums[k];
            }
            while(m <= mid || n <= j){
                if(m > mid){
                    nums[l] = temp[n];
                    n++;
                    l++;
                }else if(n > j || temp[m] <= temp[n]){
                    nums[l] = temp[m];
                    m++;
                    l++;
                }else{
                    nums[l] = temp[n];
                    res += (mid-m+1);
                    n++;
                    l++;
                }
            }
            return res;
        }

        int reversePairs(vector<int>& nums) {
            int n = nums.size();
            vector<int> temp(n, 0);
            return merge(nums, temp, 0, n-1);
        }
};