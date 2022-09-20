class Solution {
public:
    string minNumber(vector<int>& nums) {
        int num = nums.size();
        vector<string> vec;
        for(int i = 0; i < num; i++){
            vec.push_back(to_string(nums[i]));
        }
        sort(vec.begin(), vec.end(), [](string a, string b){
            return a+b < b+a;
        });
        string res = "";
        for(int i = 0; i < num; i++){
            res += vec[i];
            cout<<vec[i]<<endl;
        }
        return res;
    }
};