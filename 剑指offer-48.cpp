class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int temp = 0;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(!mp[s[i]]){
                mp[s[i]]++;
                temp++;
            }else{
                while(mp[s[i]]){
                    mp[s[i-temp]]--;
                    temp--;
                }
                mp[s[i]] = 1;
                temp++;
            }
            res = max(res, temp);
        }
        return res;
    }
};