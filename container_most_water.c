/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of the line i is at (i, ai) and (i, 0). Find two lines, which, together with
 * the x-axis forms a container, such that the container contains the most
 * water.
 * Notice that you may not slant the container.
 */ 
#include <stdio.h>
#include <stdlib.h>

//#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int max_area(int *height, int heightSize) 
{
	int i = 0, j = heightSize - 1, res = 0;
	while (i < j) {
		res = MAX(res, (j - i) * ((height[i] < height[j]) ? 
					height[i++] : height[j++]));
	}
	return res;
}

int main() {
	int height[9] = {1,8,6,2,5,4,8,3,7};
	printf("%d\n", max_area(height, 9));
}
