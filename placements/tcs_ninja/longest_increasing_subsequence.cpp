/*
 * Find the longest increasing subsequence (LIS) in a given array of integers
 * such that all elements of the subsequence are sorted in ascending order.
 * Input format The first line of the input consists of the value of n. Next
 * input is the array elements. Output format The output prints the length of
 * the longest increasing subsequence. Sample testcases Input1 
 * 9 
 * 15 27 14 38 26 55 46 65 85 
 * Output1 6
 */
#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> arr, int i = 0, int curr = 1) {
	if (i == arr.size())
		return 0;
	int mx = curr;
	for (int j = i + 1; j < arr.size(); j++) {
		if (arr[j] > arr[i])
			mx = max(mx, lis(arr, j, curr + 1));	
		else {
			arr.erase(arr.begin() + i);
			mx = max(mx, lis(arr, j, curr));
		}
	}
	return mx;
}

/*int lis_memo(vector<int> arr, int i = 0, int curr = 1, map<int, int> *memo = new map()) {
	if (memo.find(i) != memo.end())
		return memo[i];
	if (i == arr.size())
		return 0;
	int mx = curr;
	for (int j = i + 1; j < arr.size(); j++) {
		if (arr[j] > arr[i]) {
			memo[j] = 
			mx = max(mx, lis(arr, j, curr + 1));	
		} else {
			arr.erase(arr.begin() + i);
			mx = max(mx, lis(arr, j, curr));
		}
	}
	return mx;
}*/

int main() {
	vector<int> a1 = {15, 27, 14, 38, 26, 55, 46, 65, 85};
	cout << lis(a1) << endl;	//6
	vector<int> a2 = {3, 10, 2, 1, 20};
	cout << lis(a2) << endl;	//3
	vector<int> a3 = {3, 2};
	cout << lis(a3) << endl;	//1
	vector<int> a4 = {50, 3, 10, 7, 40, 80};
	cout << lis(a4) << endl;	//4
	vector<int> a5 = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	cout << lis(a5) << endl;	//6
	return 0;
}
