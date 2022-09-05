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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr)
            return res;
        q.push(root);
        while(!q.empty()){
            vector<int> line;
            int len = q.size(); // the length of current layer can be reflected in the length of queue
            for(int i = 0; i < len; i++){
                TreeNode* temp = q.front();
                q.pop();
                line.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            res.push_back(line);
        }
        return res;
    }
};