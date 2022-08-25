class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if(n <= 0)
            return vector<int>(0);
        string s(n, '0');
        DFS(s, n, 0);
        return res;
    }
    void DFS(string& s, int length, int i){
        if(i >= length) {
            pushVec(s);
            return;
        }
        for(int j = 0; j <=9; j++){
            s[i] = '0' + j;
            DFS(s, length, i+1);
        }
    }
    void pushVec(string s){
        int idx = 0;
        while(s[idx] == '0') idx++;
        string ss = s.substr(idx);
        if(ss != "")
            res.push_back(stoi(ss));
    }
};