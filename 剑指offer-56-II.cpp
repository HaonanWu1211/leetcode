// count the number in each digit, the digit value of the non-repeated number of num[i] % 3
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> num(32, 0);
        for(int i = 0; i < nums.size(); i++){
            int digit = 1;
            for(int j = 0; j < 32; j++){
                if(nums[i] & digit)
                    num[j]++;
                if(j < 31)
                    digit = digit << 1;
            }
        }
        int res = 0;
        int digit = 1;
        for(int i = 0; i < 32; i++){
            if(num[i] % 3 != 0){
                res += digit;
            }
            if(i < 31)
                digit = digit << 1;
        }
        return res;
    }
};
