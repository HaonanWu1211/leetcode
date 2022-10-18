class Solution {
public:
    void DFS(string& s, string& res, int& index){
        string temp = "";
        while(index < s.length() && s[index] == ' ') // remove pre-space
            index++;
        while(index < s.length() && s[index] != ' '){
            temp += s[index];
            index++;
        }
        if(temp == "")
            return;
        DFS(s, res, index);
        res += temp;
        res += " ";
    }
    string reverseWords(string s) {
        string res = "";
        int index = 0;
        DFS(s, res, index);
        res.pop_back();
        return res;
    }
};