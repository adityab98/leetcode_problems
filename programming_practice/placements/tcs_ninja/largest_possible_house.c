#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int arr[n][2];
	for (i = 0; i < n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	for (i = 0; i < n; i++) {
		for (j = i; j < n - i - 1; j++) {
			if (arr[j][1] > arr[j + 1][1]) {
				int t0, t1;
				t0 = arr[j][0];
				t1 = arr[j][1];
				arr[j][0] = arr[j + 1][0];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][0] = t0;
				arr[j + 1][1] = t1;
			}
		}
	}
	int max_diff = 0, house1, house2;
	for (i = 1; i < n; i++) {
		if (abs(arr[j][1] - arr[j - 1][1] > max_diff)) {
			max_diff = abs(arr[j][1] - arr[j - 1][1]);
			house1 = arr[j][0];
			house2 = arr[j - 1][0];
		}
	}
	printf("%d %d\n", house1, house2);
}
