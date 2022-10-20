class Solution {
public:
    int sumNums(int n) {
        // using logical operator to control terminating
        // the priority of && is higher than +=
        // therefore n += sumNums(n-1) shoule be added with ()
        n && (n += sumNums(n-1));
        return n;
    }
};