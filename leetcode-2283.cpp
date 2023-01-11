class Solution {
public:
    bool digitCount(string num) {
        int n = num.length();
        vector<int> count(n);
        for(int i = 0; i < n; i++){
            int index = num[i] - '0';
            if(index < n)
                count[index]++;
        }
        for(int i = 0; i < n; i++){
            if('0'+count[i] != num[i])
                return false;
        }
        return true;
    }
};
