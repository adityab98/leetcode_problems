#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findmaxsmaller(int rads[], int hts[], int n, int rad, int ht) {
    int pos = -1;
    int maxr = INT_MIN, maxh = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (rads[i] <= rad && rads[i] >= maxr && hts[i] <= ht && hts[i] >= maxh) {
            pos = i;
            maxr = rads[i];
            maxh = hts[i];
        }
    }
    return pos;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int rads[n], hts[n];
        for (int i = 0; i < n; i++) {
            cin >> rads[i] >> hts[i];   
        }
        int maxht = 0;
        int pos = findmaxsmaller(rads, hts, n, INT_MAX, INT_MAX);
        while (pos != -1) {
            maxht += hts[pos];
            pos = findmaxsmaller(rads, hts, n, rads[pos], hts[pos]);
        }
        cout << maxht << endl;
    }
    return 0;
}

/*Karan and Arjun,being best friends like to play the famous game,tower of Dubai. One day Arjun challenges Karan to build the tallest tower from a set of disks of different height and radius. The tower of Dubai can be built by stacking disks on top of each other. In order to put disk A on top of disk B, the radius and height of A must be strictly smaller than those of B. Help Karan to win the challenge.
Input format
First line of input contains number of test cases T.
First line of each test case contains value of N, the number of disks. The next N lines contains two positive integer number Ri and Hi corresponding to the radius and height of ith Disk respectively.
Input 1
1
30
17 24
26 18
26 34
13 27
2 10
8 3
20 11
17 4
7 21
17 13
9 12
10 8
21 23
14 23
26 28
13 10
19 23
28 30
17 34
23 12
4 30
30 22
8 25
15 39
1 36
17 14
21 12
4 37
21 23
2 37
Output 1
141
Input 2
1
30
16 26
28 5
6 17
10 7
18 34
16 5
16 23
28 15
15 35
21 4
19 8
9 37
25 29
12 4
20 35
1 13
19 37
23 20
7 27
30 15
11 36
29 35
22 28
3 18
13 38
27 13
21 22
2 7
30 26
30 5
Output 2
150*/
