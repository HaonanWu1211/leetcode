/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string intToString(int num){
        string s = "";
        while(num != 0){
            char c = '0' + (num%10);
            s.insert(0, 1, c);
            num = num / 10;
        }
        return s;
    }
    int stringToInt(string s){
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            num *= 10;
            int n = s[i]-'0';
            num += n;
        }
        return num;
    }
    void DFS(TreeNode* root, string& s){
        if(root == nullptr){
            s += '#';
            s += ' ';
            return;
        }
        s += intToString(root->val);
        s += ' ';
        DFS(root->left, s);
        DFS(root->right, s);
    }
    void createTree(TreeNode* &root, string s, int& index){
        if(index >= s.length())
            return;
        string str = divide(s, index);
        if(str == "#"){
            root = nullptr;
            return;
        }
        root = new TreeNode(stringToInt(str));
        createTree(root->left, s, index);
        createTree(root->right, s, index);
    }
    string divide(string data, int& index){
        string s = "";
        while(index < data.length() && data[index] != ' '){
            s += data[index];
            index++;
        }
        index++;
        return s;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        DFS(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* node = nullptr;
        if(data == "# ")
            return node;
        int index = 0;
        createTree(node, data, index);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));