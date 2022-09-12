class Solution {
public:
    int countDigitOne(int n) { //找规律,发现整数n每一位能产生多少的"1"
        int digit = 1;
        int high = n / 10;
        int low = 0;
        int cur = n % 10;
        int res = 0;
        while(high || cur){
            if(cur == 0) res += high * digit;
            else if(cur == 1) res += high * digit + low + 1;
            else res += (high+1)*digit;
            low += cur * digit;
            cur = high % 10;
            high = high / 10;
            if(high || cur)
                digit *= 10; // may can not represented by int
        }
        return res;
    }
};
