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
    void DFS(TreeNode* root, int k, int& index, int& res){
        if(root == nullptr)
            return;
        DFS(root->right, k, index, res);
        if(index == k) // ¼ôÖ¦
            return;
        index++;
        if(index == k){
            res = root->val;
            return;
        }
        DFS(root->left, k, index, res);
    }
    int kthLargest(TreeNode* root, int k) {
        int index = 0;
        int res;
        DFS(root, k, index, res);
        return res;
    }
};
