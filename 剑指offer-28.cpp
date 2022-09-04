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
    bool compare(TreeNode* TNleft, TreeNode* TNright){
        if(TNleft == nullptr && TNright == nullptr){
            return true;
        }
        if(TNleft == nullptr || TNright == nullptr){
            return false;
        }
        if(TNleft->val == TNright->val){
            return compare(TNleft->left, TNright->right) && compare(TNleft->right, TNright->left);
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
};
