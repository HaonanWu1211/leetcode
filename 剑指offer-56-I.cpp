class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int z = 0;
        for(int i = 0; i < nums.size(); i++){
            z ^= nums[i];
        }
        int digit = 1;
        while((z & digit) == 0) // priority of == is higher than &, () should not be ignored
            digit = digit << 1;
        int x = 0, y = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & digit) == 0){
                x ^= nums[i];
            }else{
                y ^= nums[i];
            }
        }
        return vector<int>{x, y};
    }
};
