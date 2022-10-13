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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *common = nullptr;
        int lena=0, lenb=0, len;
        ListNode *p=headA, *q=headB;
        while(p != nullptr){
            lena++;
            p = p->next;
        }
        while(q != nullptr){
            lenb++;
            q = q->next;
        }
        p = headA;
        q = headB;
        if(lena > lenb){
            for(int i  = 0; i < lena-lenb; i++){
                p = p->next;
            }
            len = lenb;
        }else{
            for(int i = 0; i < lenb-lena; i++){
                q = q->next;
            }
            len = lena;
        }
        for(int i = 0; i < len; i++){
            if(p == q){
                common = p;
                break;
            }
            p = p->next;
            q = q->next;
        }
        return common;
    }
};