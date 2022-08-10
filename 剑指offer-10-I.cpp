class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1)
            return n;
        int p = 0, q = 1;
        for(int i = 2; i <= n; i++){
            int r = (p + q) % 1e7;
            p = q;
            q = r;
        }
        return q;
    }
};