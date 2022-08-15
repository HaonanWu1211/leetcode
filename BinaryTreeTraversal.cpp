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
// Preorder,Inorder,Postorder all need a stack !!!
// Inorder (left -->  root  -->  right) 
// non-recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        while(root != nullptr || !s.empty()){
            while(root != nullptr){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

// recursive
class Solution {
public:
    void DFS(TreeNode* root, vector<int>& res){
        if(root == nullptr)
            return;
        DFS(root->left, res);
        res.push_back(root->val);
        DFS(root->right, res);
    } 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        DFS(root, res);
        return res;
    }
};

// Preorder (root --> left --> right)
// non-recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		while(root != nullptr || !empty(s)){
			while(root != nullptr){
				s.push(root);
				res.push_back(root->val);
				root = root->left;		
			}
			root = s.top();
			s.pop();
			root = root->right;
		}
		return res;
    }
};

// recursive
class Solution {
public:
    void DFS(TreeNode* root, vector<int>& res){
        if(root == nullptr)
            return;
        res.push_back(root->val);
        DFS(root->left, res);
        DFS(root->right, res);
    } 
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        DFS(root, res);
        return res;
    }
};

// Postorder (left --> right --> root)
// non-recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode *p = root, *prev = nullptr;
		while(!s.empty() || p != nullptr){
			while(p != nullptr){
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			if(p->right == nullptr || p->right == prev){
				res.push_back(p->val);
				prev = p;
				p = nullptr;
			}else{
				s.push(p);
				p = p->right;	
			}
		}
		return res;
    }
};

// recursive
class Solution {
public:
    void DFS(TreeNode* root, vector<int>& res){
        if(root == nullptr)
            return;
        DFS(root->left, res);
        DFS(root->right, res);
        res.push_back(root->val);
    } 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        DFS(root, res);
        return res;
    }
};
