class Solution {
public:
    // based on the idea that (x*y) % p == ((x%p) * (y%p))%p
    int power1(int a, int b, int c){
        long long res = 1;
        for(int i = 1; i <= b; i++){
            res *= a;
            res %= c;
        }
        return res;
    }
    int cuttingRope(int n) {
        if(n <= 3)
            return n-1;
        int div = n / 3;
        int mod = n % 3;
        if(mod == 0)
            return power1(3, div, 1000000007);
        else if(mod == 1)
            return ((long long)power1(3, div-1, 1000000007) * 4) % 1000000007;
        else
            return ((long long)power1(3, div, 1000000007) * 2) % 1000000007;
    }
};