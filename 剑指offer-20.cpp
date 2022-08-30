class Solution {
public:
    void clearSpace(string s, int& index){
        while(index < s.length() && s[index] == ' ')
            index++;
    }
    void dealWithSign(string s, int& index){
        if(index < s.length() && (s[index] == '+' || s[index] == '-'))
            index++;
    }
    bool dealWithInt(string s, int& index){ // unsigned
        if(index == s.length() || s[index] < '0' || s[index] > '9')
            return false;
        while(index < s.length() && s[index] >= '0' && s[index] <= '9')
            index++;
        return true;
    }
    bool deaWithFloat(string s, int& index){
        if(index == s.length())
            return false;
        if(s[index] == '.'){
            index++;
            return dealWithInt(s, index);
        }
        else{
            bool res = dealWithInt(s, index);
            if(index < s.length() && s[index] == '.'){
                index++;
                while(index < s.length() && (s[index] >= '0' && s[index] <= '9'))
                    index++;
            }
            return res;
        }
    }
    bool dealWithExp(string s, int& index){
        if(index < s.length() && (s[index] == 'e' || s[index] == 'E')){
            index++;
            return true;
        }
        return false;
    }
    bool isNumber(string s) {
        int index = 0;
        clearSpace(s, index);
        dealWithSign(s, index);
        if(!deaWithFloat(s, index))
            return false;
        if(dealWithExp(s, index)){
            dealWithSign(s, index);
            if(!dealWithInt(s, index))
                return false;
        }
        clearSpace(s, index);
        if(index == s.length())
            return true;
        return false; 
    }
};