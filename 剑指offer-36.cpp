/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void DFS(Node *root, Node* &pre){//inorder 绑定需要对完整的数据类型进行绑定 Node* & -- YES Node& * -- NO
        if(root == nullptr)
            return;
        DFS(root->left, pre);
        if(pre){
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        DFS(root->right, pre);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return root;
        Node* pre = nullptr;
        Node *first, *last;
        Node* p = root;
        while(p->left){
            p = p->left;
        }
        first = p;
        p = root;
        while(p->right){
            p = p->right;
        }
        last = p;
        DFS(root, pre);
        first->left = last;
        last->right = first;
        return first;
    }
};