#include<bits/stdc++.h>
using namespace std;
void QuickSort(vector<int> &vec, int begin, int end){
	if(begin >= end)
		return;
	int pivot = vec[begin];
	int i = begin, j = end;
	while(i < j){
		while(i < j && vec[j] >= pivot) j--;
		vec[i] = vec[j]; 
		while(i < j && vec[i] <= pivot) i++;
		vec[j] = vec[i];	
	}
	vec[j] = pivot;
	QuickSort(vec, begin, j-1);
	QuickSort(vec, j+1, end);
}

int main(){
	int a[] = {10, 2, 5, 3, 1, 7};
	vector<int> vec(a, a+6);
	QuickSort(vec, 0, vec.size()-1);
	for(int i = 0; i < vec.size(); i++){
		cout<<vec[i]<<endl;
	}
	return 0;
}
