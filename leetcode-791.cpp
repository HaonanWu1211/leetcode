// 主要思想
// 计数排序
class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        string res;
        for(int i = 0; i < order.length(); i++){
            if(mp.find(order[i]) != mp.end()){
                res.append(mp[order[i]], order[i]);
                mp.erase(order[i]);
            }
        }
        map<char, int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); iter++){
            res.append(iter->second, iter->first);
        }
        return res;
    }
};
