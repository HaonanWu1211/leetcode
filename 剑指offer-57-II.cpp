class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 2;
        int sum = 3;
        vector<vector<int>> res;
        deque<int> dq;
        dq.push_back(left);
        dq.push_back(right);
        while(left + left + 1 <= target){
            if(sum == target){
                res.push_back(vector<int>(dq.begin(), dq.end()));
                sum -= left;
                left++;
                dq.pop_front();
            }
            else if(sum < target){
                right++;
                sum += right;
                dq.push_back(right);
            }
            else{
                sum -= left;
                left++;
                dq.pop_front();
            }
        }
        return res;
    }
};
