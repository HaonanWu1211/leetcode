class Solution {
public:
    bool isBinarySearchTree(vector<int>& postorder, int i, int j){
        if(i >= j)
            return true;
        int root = postorder[j];
        int mid = i;
        while(mid < j && postorder[mid] < root) mid++;
        for(int k = mid + 1; k < j; k++){
            if(postorder[k] < root)
                return false;
        }
        return isBinarySearchTree(postorder, i, mid-1) && isBinarySearchTree(postorder, mid, j-1);
    }
    bool verifyPostorder(vector<int>& postorder){
        int len = postorder.size();
        if(len == 0)
            return true;
        return isBinarySearchTree(postorder, 0, len-1);
    }
};