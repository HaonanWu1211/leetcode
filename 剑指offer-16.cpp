class Solution {
public:
    double Pow(double x, long long n){
        if(n == 0)
            return 1;
        double res = Pow(x, n/2);
        return n % 2 == 0 ? (res*res) : (res*res*x);
    }
    double myPow(double x, int n) {
        return n >= 0 ? Pow(x, n) : (1.0 / Pow(x, -1*(long long)n));
    }
};