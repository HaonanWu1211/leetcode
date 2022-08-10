class Solution {
public:
    int numWays(int n) {
        if(n == 0) // need to consider the situation when the number of steps is zero !
            return 1;
        if(n == 1 || n == 2)
            return n;
        int p = 1, q = 2;
        for(int i = 3; i <= n; i++){
            int r = (p + q) % 1000000007;
            p = q;
            q = r;
        }
        return q;
    }
};