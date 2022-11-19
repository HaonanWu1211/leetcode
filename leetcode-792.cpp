class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        vector<queue<pair<int, int>>> vec(26);
        for(int i = 0; i < words.size(); i++){
            pair<int, int> temp;
            temp.first = i;
            temp.second = 0;
            vec[words[i][0]-'a'].push(temp);
        }
        for(int i = 0; i < s.length(); i++){
            queue<pair<int, int>> &q = vec[s[i]-'a'];
            int s = q.size();
            while(s--){
                pair<int, int> p = q.front();
                q.pop();
                p.second = p.second+1;
                if(p.second == words[p.first].length())
                    res++;
                else
                    vec[words[p.first][p.second]-'a'].push(p);
            }
        }
        return res;
    }
};
