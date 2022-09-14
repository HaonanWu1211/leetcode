class Solution {
public:
    int findNthDigit(int n) {
        long long num = 9;
        int digit = 1;
        long long start = 1;
        while(n > num*digit){
            n -= num*digit;
            num *= 10;
            digit++;
            start *= 10;
        }
        start += ((n-1) / digit);
        string str = to_string(start);
        int res = str[(n-1)%digit] - '0';
        return res;

    }
};