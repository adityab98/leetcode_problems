/*
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, 
		int nums2Size)
{
	int low1 = 0, low2 = 0, high1 = nums1Size - 1, high2 = nums2Size - 1, 
	    med1, med2;
	med1 = 0;
	med2 = INT_MAX;
	bool flag = false;
	while (low1 <= high1 && low2 <= high2) {
		int m1 = (high1 - low1) / 2;
		int m2 = (high2 - low2) / 2;
		if (abs(nums1[m1] - nums2[m2]) < abs(med1 - med2)) {
			med1 = nums1[m1];
			med2 = nums2[m2];
		}
		if (flag) {
			if (nums1[m1] < nums2[m2])
				low1 = m1;
			else
				high1 = m1;
			flag = true;
		}
		else {
			if (nums2[m2] < nums1[m1])
				low2 = m2;
			else
				high2 = m2;
			flag = false;
		}
		if (nums1[m1] == nums2[m2])
			break;
	}
	if (nums1Size + nums2Size % 2 == 0)
		return ((double)med1 + (double)med2) / 2.0;
	else
		if (med1 < med2)
			return (double) med1;
		else
			return (double) med2;
}

int main()
{
	int nums1[2] = {1, 3};
	int nums2[1] = {2};
	printf("%lf\n", findMedianSortedArrays(nums1, 2, nums2, 2));
}
