/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNodeCur(ListNode*& head, ListNode* p, int val, ListNode* pre){ // remember to add &
        if(p == nullptr)
            return;
        if(p->val == val){
            if(pre == nullptr){
                head = p->next;
            }
            else{
                pre->next = p->next;
            }
        }
        else{
            deleteNodeCur(head, p->next, val, p);
        }
    }
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pre = nullptr, *p = head;
        deleteNodeCur(head, p, val, pre);
        return head;
    }
};