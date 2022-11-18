class Solution {
public:
    vector<long long> pow_2;
    const int mod = 1e9 + 7;
    long long add(long long a, long long b){
        return (a%mod + b%mod) % mod;
    }
    long long multiply(long long a, long long b){
        return (a%mod * b%mod) % mod;
    }
    int sumSubseqWidths(vector<int>& nums) {
        // calculate the contribution a element to the final result
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // num of sub-sequences element-i acted as the maximum value
        // power(2, i)
        // num of sub-sequences element-i acted as the minimum value
        // power(2, n-1-i)
        // the contribution element-i to the final result is (power(2, i) - power(2, n-1-i))*nums[i]
        long long temp = 1;
        pow_2.push_back(temp);
        for(int i = 1; i < n; i++){
            pow_2.push_back(multiply(pow_2[i-1], 2));
        }
        long long res = 0;
        for(int i = 0; i < n; i++){
            res = add(res, (pow_2[i]-pow_2[n-1-i])*nums[i]);
        }
        return res;
    }
};
