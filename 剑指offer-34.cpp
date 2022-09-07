/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void DFS(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int target, int& sum){
        if(root == nullptr)
            return;
        sum += root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(sum == target)
                res.push_back(path);
        }
        DFS(res, path, root->left, target, sum);
        DFS(res, path, root->right, target, sum);
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int sum = 0;
        DFS(res, path, root, target, sum);
        return res;
    }
};