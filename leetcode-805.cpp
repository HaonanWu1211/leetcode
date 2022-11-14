class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        if(nums.size() == 1)
            return false;
        int n = nums.size(), m = n/2;
        set<int> left;
        int acc = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i]*n - acc; // let the average value to be zero
        }
        // find a subset, its average value is the same as the average value of the fullset
        // each element substracts the average value, the problem becomes
        // find a subset, its sum is zero (divide may generate fraction)

        // let the average value of a vector become an integer (or mistakes may happen when substract the average value)
        // each element multiplies the size of the vector
        // then the average value becomes the sum of the vector
        // reduce the time complexity from O(n*2^n) to O(n*2^(n/2))
        for(int i = 1; i < (1<<m); i++){
            int tol = 0;
            for(int j = 0; j < m; j++){
                if(i & (1 << j)){
                    tol += nums[j];
                }
            }
            if(tol == 0)
                return true;
            left.insert(tol);
        }
        int right_acc = accumulate(nums.begin()+m, nums.end(), 0);
        for(int i = 1; i < (1<<(n-m)); i++){
            int tol = 0;
            for(int j = m; j < n; j++){
                if(i & (1<<(j-m))){
                    tol += nums[j];
                }
            }
            if(tol == 0 || (tol != right_acc && left.count(-tol)))
                return true;
        }
        return false;
    }
};
