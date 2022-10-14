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
    void DFS(TreeNode* root, int& depth, int& res){
        if(root == nullptr)
            return;
        depth++;
        if(!root->left && !root->right)
            res = max(res, depth);
        DFS(root->left, depth, res);
        DFS(root->right, depth, res);
        depth--;
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int res = 0; // the minimum value of the depth is zero
        DFS(root, depth, res);
        return res;
    }
};

// optimization
// height of the binary tree equals max(height of the left binary tree, height of the right binary tree)+1
