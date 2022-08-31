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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p=head, *q=head;
        for(int i = 1; i <= k-1 && p; i++){
            p = p->next;
        }
        if(!p)
            return nullptr;
        while(p->next){
            p = p->next;
            q = q->next;
        }
        return q;
    }
};