#include<bits/stdc++.h>
using namespace std;

int transform(string s){
    int res = 0;
    int index = 0;
    while(index < s.length()){
        res = res * 10;
        int temp = s[index] - '0';
        res = res + temp;
        index++;
    }
}

struct TNode{
    int val;
    struct TNode* left;
    struct TNode* right;
    TNode(int val_):val(val_),left(nullptr),right(nullptr){}
};

// create the binary tree in pre-order
void createTreePreOrder(TNode*& root){ // pay attention to *& here
    string s;
    cin>>s;
    if(s == "null"){
        root == nullptr;
    }else{
        int val = 0, index = 0;
        while(index < s.length()){
            int temp = s[index] - '0';
            val *= 10;
            val += temp;
            index++;
        }
        root = new TNode(val);
        createTree(root->left);
        createTree(root->right);
    }
}

// create the binary tree in level-order
void createTreeLevelOrder(TNode* root){
    queue<TNode*> q;
    string s;
    cin>>s;
    if(s != "null"){
        root = new TNode(transform(s));
        q.push(root);
    }
    while(!q.empty()){
        TNode* t = q.front();
        q.pop();
        cin>>s;
        if(s != "null"){
            t->left = new TNode(transform(s));
            q.push(t->left);
        }
        cin>>s;
        if(s != "null"){
            t->right = new TNode(transform(s));
            q.push(t->right)
        }
    }
}

// pre-Traversal to test the correctness of creating the binary tree
vector<int> preTraversal(TNode* root){
    stack<TNode*> s;
    TNode* p = root;
    vector<int> res;
    while(!s.empty() || p!=nullptr){
        while(p!=nullptr){
            res.push_back(p->val);
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        p = p->right;
    }
    return res;
}

int main(){
    // string s;
    // cin>>s;
    // int val = 0, index = 0;
    // while(index < s.length()){
    //     int temp = s[index] - '0';
    //     val *= 10;
    //     val += temp;
    //     index++;
    // }
    // int n = val;
    TNode* root;
    // createTreePreOrder(root);
    createTreeLevelOrder(root);
    vector<int> res = preTraversal(root);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}