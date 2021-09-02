/*
 * Chulbul Pandey is following N thieves, which are right now in a 2D grid. Each
 * thief at t=0, decides to move in certain fixed direction. Each thief moves
 * with same speed. These fixed directions are North, East, West and South. Two
 * or more thieves, however, vanish whenever they meet at any place at same
 * time, t>0.
 * You have to tell what is the final number of thieves left at t=infinity.
 * Note: No two thieves will have the same starting point at t=0.
 * Input format
 * First line, T, the number of testcases. Each testcase consists of N lines.
 * Each line contains x y z. x, y denotes the intial position of the thief. z is
 * one of 'N','E','W','S', denoting the direction in which this thief will move.
 * Output format
 * For each testcase, required answer in one line.
 * Code constraints
 * 1 ≤ T ≤ 100
 * 1 ≤ N ≤ 50
 * -1000 ≤ x, y ≤ 1000
 * Sample testcases
 * Input 1
 * 1
 * 4
 * 0 0 N
 * 10 10 W
 * 20 20 N
 * 30 30 E
 * Output 1
 * 2
 * Input 2
 * 1
 * 4
 * 0 0 N
 * 10 10 W
 * 20 20 N
 * 30 30 E
 * Output 2
 * 2
 */
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define PI 3.14159265
#define N 50

/* array of N numbers. 0th col is X, 1st col is Y, 2nd col is direction,
 * 3rd column is dead status.
 * 0=N, 1=E, 2=W, 3=S
 * 0=alive, 1=dead
 */
int remaining_thieves(int arr[N][4], int n) {
	int dead_thieves = 0;
	for (int i = 0; i < n; i++) {
		// thief is dead
		float x1_slope;
		// if direction is N or S
		if (arr[i][3] == 0 || arr[i][3] == 3) {
			x1_slope = 
		}
		if (arr[i][3] == 1)
			continue;
		for (int j = i + 1; j < n; j++) {
			if (arr[j][3] == 1)
				continue;
			float x2_slope, hypotenuse_slope, angle1, angle2;
			x2_slope = 
			hypotenuse_slope = abs((float)arr[j][1] - (float)arr[i][1]) /
				abs((float)arr[j][0] - (float)arr[i][0]);
		}
	}
}






























