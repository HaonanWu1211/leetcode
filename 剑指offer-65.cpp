class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            // unsigned int can avoid the overflow caused by int
            unsigned int c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};