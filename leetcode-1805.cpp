class Solution {
public:
    void remove_zero(string& str){
        int i = 0;
        while(str[i] == '0')
            i++;
        str = str.substr(i);
    }
    int numDifferentIntegers(string word) {
        set<string> s;
        string str = "";
        int i = 0;
        while(i < word.size()){
            while(i < word.size() && word[i] >= 'a'){
                i++;
            }
            while(i < word.size() && word[i] < 'a'){
                str += word[i];
                i++;
            }
            if(str != ""){
                remove_zero(str);
                s.insert(str);
                str = "";
            }
        }
        return s.size();
    }
};
