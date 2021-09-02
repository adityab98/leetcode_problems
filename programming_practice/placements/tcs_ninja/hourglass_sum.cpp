/*
 * https://www.geeksforgeeks.org/maximum-sum-hour-glass-matrix/
 */

#include <bits/stdc++.h>
using namespace std;

#define N 6

int max_hourglass(int matrix[N][N]) {
	int max_sum = INT_MIN;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < N - 2; j++) {
			max_sum = max(max_sum, matrix[i][j] + matrix[i][j + 1]
					+ matrix[i][j + 2] + matrix[i + 1][j + 1] + matrix[i + 2][j]
					+ matrix[i + 2][j + 1] + matrix[i + 2][j + 2]);
		}
	}
	return max_sum;
}

int main() {
	int matrix[N][N] = {
					{1, 2, 3, 0, 0},
                    {0, 0, 0, 0, 0},
                    {2, 1, 4, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 1, 0}};
	cout << max_hourglass(matrix) << endl;
}
