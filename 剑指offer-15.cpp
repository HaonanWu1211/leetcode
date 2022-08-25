class Solution {
public:
    int hammingWeight(uint32_t n) {
        int d;
        int num = 0;
        for(int i = 1; i <= 32; i++){
            if(i == 1){
                d = 1;
            }else{
                d = d << 1;
            }
            if(n & d) num++;
        }
        cout<<num<<endl;
    }
};