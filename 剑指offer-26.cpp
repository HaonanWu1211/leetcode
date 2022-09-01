/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool compare(TreeNode* A, TreeNode* B){
        if(B == nullptr)
            return true;
        else{
            if(A == nullptr)
                return false;
        }
        if(A->val != B->val)
            return false;
        return compare(A->left, B->left) && compare(A->right, B->right);
    }
    void DFS(TreeNode* A, TreeNode* B, bool& flag){
        if(A == nullptr || flag)
            return;
        flag = compare(A, B);
        DFS(A->left, B, flag);
        DFS(A->right, B, flag);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == nullptr)
            return false;
        bool flag = false;
        DFS(A, B, flag);
        return flag;
    }
};