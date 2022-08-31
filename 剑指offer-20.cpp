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

// use finite state automata to solve
// note that accepted states and other states should be represented using different states !!!
// finite state automata can solve the problem which requires to judge whether the string satisfies corresponding forms
class Solution {
public:
    enum CHARTYPE{ // define different types of CHAR using enum, different states can be represented by different digits
        CHAR_SPACE,
        CHAR_SIGN,
        CHAR_DIGIT,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_OTHER,
    };
    CHARTYPE toChartype(char c){ // define the corresponding relationship between char and CHARTYPE
        if(c == ' ')
            return CHAR_SPACE;
        else if(c == '+' || c == '-')
            return CHAR_SIGN;
        else if(c >= '0' && c <= '9')
            return CHAR_DIGIT;
        else if(c == 'e' || c == 'E')
            return CHAR_EXP;
        else if(c == '.')
            return CHAR_POINT;
        else
            return CHAR_OTHER;
    }
    bool isNumber(string s) {
        map<int, map<CHARTYPE, int>> transfer{ // define state transfer matrix using map<int, map<CHARTYPE, int>>
            {
                0, {{CHAR_SPACE, 0},{CHAR_SIGN, 1},{CHAR_DIGIT,2},{CHAR_POINT,3}}
            },
            {
                1, {{CHAR_DIGIT, 2},{CHAR_POINT,3}}
            },
            {
                2, {{CHAR_DIGIT, 2},{CHAR_POINT,4},{CHAR_EXP,5},{CHAR_SPACE,8}}
            },
            {
                3, {{CHAR_DIGIT, 4}}
            },
            {
                4, {{CHAR_DIGIT, 4},{CHAR_EXP, 5},{CHAR_SPACE,8}}
            },
            {
                5,{{CHAR_SIGN, 6},{CHAR_DIGIT, 7}}
            },
            {
                6,{{CHAR_DIGIT, 7}}
            },
            {
                7,{{CHAR_DIGIT, 7},{CHAR_SPACE, 8}}
            },
            {
                8,{{CHAR_SPACE, 8}}
            }
        };
        int state = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            CHARTYPE CT = toChartype(c);
            if(transfer[state].find(CT) == transfer[state].end())
                return false;
            else{
                state = transfer[state][CT];
            }
        }
        if(state == 2 || state == 4 || state == 7 || state == 8) // if the final state is a accepted state, accept it
            return true;
        else
            return false;
    }
};  
