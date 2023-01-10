class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> target(n), perm(n);
        iota(target.begin(), target.end(), 0);
        iota(perm.begin(), perm.end(), 0);
        int res = 0;
        while(true){
            res++;
            vector<int> arr(n);
            for(int i = 0; i < n; i++){
                if(i & 1){
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
                else{
                    arr[i] = perm[i / 2];
                }
            }
            perm = arr;
            if(perm == target){
                break;
            }
        } 
        return res;
    }
};
