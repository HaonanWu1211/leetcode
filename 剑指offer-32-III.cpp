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
        bool isReverse = false;
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> res; // or use deque to save
            for(int i = 0; i < len; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                res.push_back(temp->val);
            }
            if(isReverse){ 
                reverse(res.begin(), res.end());
            }
            result.push_back(res);
            isReverse = !isReverse;
        }
        return result;
    }
};