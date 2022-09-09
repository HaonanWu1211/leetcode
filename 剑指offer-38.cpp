// Way 1 --- backtracking + pruning
class Solution {
public:
    void DFS(string& str, string s, vector<string>& res, vector<bool>& visit){
        if(str.length() == s.length()){
            res.push_back(str);
            return;
        }
        for(int i = 0; i < s.length(); i++){
            if(visit[i] || (i > 0 && !visit[i-1] && s[i-1] == s[i])) // 剪枝--重复的字符必须从左往右按序放置，需要先排序
                continue;
            visit[i] = true;
            str += s[i];
            DFS(str, s, res, visit);
            visit[i] = false;
            str.pop_back();
        }
    }

    vector<string> permutation(string s) {
        string str = "";
        vector<bool> visit(s.length(), false);
        vector<string> res;
        sort(s.begin(), s.end());
        DFS(str, s, res, visit);
        return res;
    }
};

// Way 2 --- use next_permutation function
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        do{
            res.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        return res;
    }
};