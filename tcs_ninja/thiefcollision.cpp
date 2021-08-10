// You are using GCC
#include <iostream>
using namespace std;
#define N 50

bool willthievescollide(int x1, int x2, int y1, int y2, char z1, char z2) {
    
}

void checkcollision(int thieves[N][2], int size) {
    int numcollisions = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (thieves[i][0] == thieves[j][0] &&
            thieves[i][1] == thieves[j][1]) {
                thieves[i][0] = thieves[j][0] = thieves[i][1] = thieves[j][1] = 1001;
            }
        }
    }
}
/*
Chulbul Pandey is following N thieves, which are right now in a 2D grid. Each thief at t=0, decides to move in certain fixed direction. Each thief moves with same speed. These fixed directions are North, East, West and South. Two or more thieves, however, vanish whenever they meet at any place at same time, t>0.
You have to tell what is the final number of thieves left at t=infinity.
Note: No two thieves will have the same starting point at t=0.
Input format
First line, T, the number of testcases. Each testcase consists of N lines. Each line contains x y z. x, y denotes the intial position of the thief. z is one of 'N','E','W','S', denoting the direction in which this thief will move.
Output format
For each testcase, required answer in one line.
Code constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 50
-1000 ≤ x, y ≤ 1000
Sample testcases
Input 1
1
4
0 0 N
10 10 W
20 20 N
30 30 E
Output 1
2
Input 2
1
4
0 0 N
10 10 W
20 20 N
30 30 E
Output 2
2
*/
