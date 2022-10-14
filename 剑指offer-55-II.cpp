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
    int DFS(TreeNode* root){ // use depth to judge isBalanced, if is Balanced, return depth, else, return -1;
        if(root == nullptr)
            return 0;
        int leftHeight = DFS(root->left);
        if(leftHeight == -1)
            return -1;
        int rightHeight = DFS(root->right);
        if(rightHeight == -1 || abs(leftHeight-rightHeight)>1){
            return -1;
        }
        return max(leftHeight, rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        int res = DFS(root);
        return res == -1 ? false : true;
    }
};
