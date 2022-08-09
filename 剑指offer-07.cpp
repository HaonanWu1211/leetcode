class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prebegin, int preend, int inbegin, int inend){
        // error --- use the same index range for preorder and inorder
        // two index ranges [prebegin, preend] and [inbegin, inend] must be used to indicate the index range of preorder and inorder 
        if(prebegin > preend)
            return nullptr;
        int root_val = preorder[prebegin];
        TreeNode* root = new TreeNode(root_val);
        int i = inbegin;
        while(inorder[i] != root_val) i++;
        int num_left = i-inbegin;
        int num_right = inend - i;
        root->left = build(preorder, inorder, prebegin+1, prebegin+num_left, inbegin, i-1);
        root->right = build(preorder, inorder, prebegin+num_left+1, preend, i+1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};