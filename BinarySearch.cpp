#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> vec, int target){
    int low = 0, high = vec.size()-1, mid;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(vec[mid] == target)
            return mid;
        else if(vec[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int> vec = {2, 4, 5, 7, 9, 10};
    int target = 7;
    cout<<BinarySearch(vec, target)<<endl;
    system("pause");
    return 0;
}