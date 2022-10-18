class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < k; i++){
            if(dq.empty())
                dq.push_back(nums[i]);
            else{
                while(!dq.empty() && nums[i] > dq.back()){
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        res.push_back(dq.front());
        for(int i = k; i < nums.size(); i++){
            if(nums[i-k] == dq.front())
                dq.pop_front();
            while(!dq.empty() && nums[i] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            res.push_back(dq.front());
        }
        return res;
    }
};