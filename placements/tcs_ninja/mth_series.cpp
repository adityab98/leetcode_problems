/*
 * Find the nth term of the series.
 * 1, 1, 2, 3, 4, 9, 8, 27, 16, 81, 32, 243,64, 729, 128, 2187 ….
 * This series is a mixture of 2 series – all the odd terms in 
 * this series form a geometric series and all the even terms 
 * form yet another geometric series. 
 * Write a program to find the Nth term in the series.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> series(n/2 + 1);
    if (n % 2 != 0) {
        for (int i = 0; i < n/2 + 1; i++) {
            series[i] = i;
        }
        cout << series.back() << endl;
    }
    else {
        for (int i = 0; i < n/2; i++) {
            series[i] = 2 * i;
        }
        cout << series[series.size() - 2] << endl;
    }
}
