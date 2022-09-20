class Solution {
public:
    void DFS(string str, int digit, int& res){
        if(digit == str.length()){
            res++;
            return;
        }
        DFS(str, digit+1, res); // one digit
        if(digit < str.length()-1 && str[digit] != '0' && str.substr(digit, 2) < "26") // two digits if possible
            DFS(str, digit+2, res);
    }

    int translateNum(int num) {
        string str = to_string(num);
        int res = 0, digit = 0;
        DFS(str, digit, res);
        return res;
    }
};