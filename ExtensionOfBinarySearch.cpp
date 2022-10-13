#include<bits/stdc++.h>
using namespace std;
// Extension of using binary search
// using binary search to find the corresponsing element is listed in BinarySearch.cpp

// using binary search to find the first element which is greater than the given target element
int BinarySearch1(vector<int> vec, int target){
    int low = 0, high = vec.size()-1, mid;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(vec[mid] <= target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if(low < vec.size())
        return vec[low];
    else
        return -1;
}

// using binary search to find the last element which is less than the given target element
int BinarySearch2(vector<int> vec, int target){
    int low = 0, high = vec.size()-1, mid;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(vec[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if(high >= 0)
        return vec[high];
    else
        return -1;
}

int main(){
    vector<int> vec = {2, 4, 5, 7, 9, 10};
    int target1 = 7;
    int target2 = 11;
    int target3 = 1;
    cout<<BinarySearch1(vec, target1)<<endl;
    cout<<BinarySearch2(vec, target1)<<endl;
    cout<<BinarySearch1(vec, target2)<<endl;
    cout<<BinarySearch2(vec, target3)<<endl;
    system("pause");
    return 0;
}