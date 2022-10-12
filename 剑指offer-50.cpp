class Solution { // use vector to save all keys can reduce time complexity in the second iteration
public:
    char firstUniqChar(string s) {
        char res = ' ';
        map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
                mp[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] == 1)
                return s[i];
        }
        return res;
    }
};