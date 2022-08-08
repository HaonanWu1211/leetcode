class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        ListNode* p = head;
        vector<int> res;
        while(p != nullptr){
            s.push(p->val);
            p = p->next;
        }
        while(!empty(s)){
            int temp = s.top();
            s.pop();
            res.push_back(temp);
        }
        return res;
    }
};