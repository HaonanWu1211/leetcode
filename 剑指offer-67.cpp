class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while(i < str.length() && str[i] == ' ')
            i++;
        if(i == str.length())
            return 0;
        if(str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')){
            return 0;
        }
        int sign = 1;
        if(str[i] == '+' || str[i] == '-'){
            sign = str[i] == '+' ? 1 : -1;
            i++;
        }
        if(i == str.length() || !(str[i] >= '0' && str[i] <= '9')){
            return 0;
        }
        long long res = 0;
        while(str[i] >= '0' && str[i] <= '9'){
            int digit = str[i] - '0';
            res *= 10;
            res += digit;
            if(sign * res > INT_MAX || sign * res < INT_MIN)
                break;
            i++;
        }
        if(sign * res > INT_MAX)
            return INT_MAX;
        else if(sign * res < INT_MIN)
            return INT_MIN;
        else
            return sign * res;
    }
};