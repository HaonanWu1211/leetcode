class Solution {
public:
    int lastRemaining(int n, int m) {
        // the changes of the subscript of the last remaining digit
        // 0 -- when remain 1 people
        // f(n-1, m) -- when remain n-1 peole --> f(n, m) -- when remain n people its subscript
        // if x = m % n
        // when length is n-1:
        // x x+1 ... n-1 0 ... x-2
        // when length is n
        // 0 1 ... x-2 x-1 x x+1 ... n-1
        // f(n-1, m) --> (f(n-1, m) + m % n) % n
        return n == 1 ? 0 : (lastRemaining(n-1, m) + m) % n;
    }
};