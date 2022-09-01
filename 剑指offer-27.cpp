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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        TreeNode* mirrorLeft = mirrorTree(root->left);
        TreeNode* mirrorRight = mirrorTree(root->right);
        root->right = mirrorLeft;
        root->left = mirrorRight;
        return root;
    }
};