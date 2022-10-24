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
    void dfs(TreeNode* root, vector<TreeNode*>& path, TreeNode* p, bool& tag){
        if(root == NULL || tag == true)
            return;
        path.push_back(root);
        if(root == p){
            tag = true;
            return;
        }
        dfs(root->left, path, p, tag);
        if(tag)
            return;
        dfs(root->right, path,  p, tag);
        if(tag)
            return;
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        if(root == NULL)    
            return root;
        bool tag = false;
        dfs(root, path1, p, tag);
        tag = false;
        dfs(root, path2, q, tag);
        int i = 0;
        while(i < path1.size() && i < path2.size() && path1[i] == path2[i]){
            i++;
        }
        return path1[i-1];
    }
};