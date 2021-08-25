/*
 * Coders here is a simple task for you, you have given an array of size N and
 * an integer M. Your task is to calculate the difference between maximum sum
 * and minimum sum of N-M elements of the given array. Constraints: 1<=t<=10
 * 1<=n<=1000 1<=a[i]<=1000 Input format First line contains an integer T
 * denoting the number of testcases. First line of every testcase contains two
 * integer N and M. Next line contains N space separated integers denoting the
 * elements of array Output format For every test case print your answer in new
 * line Sample testcases 
 * Input1 
 * 1 
 * 5 1 
 * 1 2 3 4 5 
 * Output1 
 * 4
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int s1, s2;
	s1 = s2 = 0;
	for (int i = 0; i < m; i++) {
		s1 += arr[i];
	}
	for (int i = n-1; i >= n-m; i--) {
		s2 += arr[i];
	}
	cout << s2 - s1 << endl;
	return 0;
}
