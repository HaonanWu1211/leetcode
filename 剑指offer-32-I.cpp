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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == nullptr)
            return res;
        q.push(root); // Do not forget to push root
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop(); // Do not forget to pop the visited node
            res.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return res;
    }
};