class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> mp;
        int sum = 0, temp = lowLimit;
        while(temp > 0){
            sum += temp % 10;
            temp = temp / 10;
        }
        mp[sum] = 1;
        int maxcount = 1;
        for(int i = lowLimit+1; i <= highLimit; i++){
            int temp1=1e5, temp2=1e4, temp3=1e3, temp4=1e2, temp5=1e1;
            int label;
            if(i % temp1 == 0){
                label = 5;
            }else if(i % temp2 == 0){
                label = 4;
            }else if(i % temp3 == 0){
                label = 3;
            }else if(i % temp4 == 0){
                label = 2;
            }else if(i % temp5 == 0){
                label = 1;
            }else{
                label = 0;
            }
            sum -= (label*9-1);
            mp[sum] += 1;
            if(mp[sum] > maxcount)
                maxcount = mp[sum];
        }
        return maxcount;
    }
};
