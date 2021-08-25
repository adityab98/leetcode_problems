/*
 * Given a maximum of four digit to the base 17 (10 – A, 11 – B, 12 – C, 
 * 13 – D … 16 – G} as input, output its decimal value.
 * Input – 1A, Expected Output – 27
 * Input – 23GF, Expected Output – 10980
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int septa_to_dec(char c) {
    switch (c) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        case 'G':
            return 16;
        default:
            return c - '0';
    }
}

int main() {
    string num;
    cin >> num;
    int dec = 0;
    int n = num.size();
    for (int i = 0; i < n; i++) {
        int position_factor = 1;
        for (int j = n - 1; j > i; j--) {
            position_factor *= 17;
        }
        //cout << num[i] << " " << position_factor << endl;
        dec += position_factor * septa_to_dec(num[i]);
    }
    cout << dec << endl;
}
