// binary search
// only compare numbers[mid] with numbers[j]
// or the algorithm will be wrong
// for example, [1, 2, 3, 4, 5] [3, 4, 5, 1, 2] for the situation of numbers[mid] > numbers[i]
class Solution {
public:
    int minArray(vector<int>& numbers) {
		int n = numbers.size();
		if(n == 1)
			return numbers[0];
		int i = 0, j = numbers.size()-1, mid;
		while(i < j){
			mid = (i + j) >> 1;
			if(numbers[mid] > numbers[j]){
				i = mid+1;
			}
			else if(numbers[mid] < numbers[j]){
				j = mid;
			}
			else{
				j = j-1;
			}
		}
		return numbers[i];
    }
};
