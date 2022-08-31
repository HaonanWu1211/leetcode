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
    ListNode* reverse(ListNode* head, ListNode*& tail){
        if(head == nullptr || head->next == nullptr){
            tail = head;
            return head;
        }
        ListNode* node = reverse(head->next, tail);
        head->next = nullptr;
        node->next = head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* tail;
        reverse(head, tail);
        return tail;
    }
};