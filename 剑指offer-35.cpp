/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// way 1 -- 哈希表建立新旧链表对应节点的关系 空间复杂度O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* cur = head;
        if(head == nullptr)
            return nullptr;
        while(cur){
            mp[cur] = new Node(cur->val); 
            cur = cur->next;
        }
        cur = head;
        while(cur){
            if(!cur->next) mp[cur]->next = nullptr;
            else mp[cur]->next = mp[cur->next];
            if(!cur->random) mp[cur->random] = nullptr;
            else mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};

// way 2 拼接 + 拆分 空间复杂度O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node *pre = head, *cur;
        while(pre){
            cur = new Node(pre->val);
            cur->next = pre->next;
            pre->next = cur;
            pre = cur->next;
        }
        pre = head, cur = head->next;
        while(pre){
            cur->random = pre->random == nullptr ? nullptr : pre->random->next;
            pre = pre->next->next;
            if(pre)
                cur = pre->next;
        }
        Node* newhead = head->next;
        pre = head, cur = head->next;
        while(cur->next){
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return newhead;
    }
};