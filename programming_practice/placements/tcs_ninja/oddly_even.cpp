/*
 * Given a maximum of 100 digit numbers as input, 
 * find the difference between the sum of odd and even position digits
 * note: absolute difference
 * 4567, 2
 * 5476, 2
 * 9834698765123, 1
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    string num;
    cin >> num;
    int result = 0;
    for (int i = 0; i < num.size(); i++) {
        int n = num[i] - '0';
        if (i % 2 == 0)
            result += n;
        else
            result -= n;
    }
    if (result < 0)
        result *= -1;
    cout << result << endl;
}
