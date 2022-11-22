// 二分查找 + 容斥原理 
class Solution {
public:
    const int mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        int t = a*b/__gcd(a,b);
        long long l = 2, r = (long long) min(a, b)*n;
        while(l <= r){
            long long mid = (l+r) >> 1; 
            int temp = (mid/a)+(mid/b)-(mid/t);
            if(temp >= n){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return (r+1)%mod;
    }
};
