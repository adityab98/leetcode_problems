/*
 * Amarasimha wanted to know the final position of a person, who starts from 
 * the origin 0 0 and travels per following scheme.
 * He first turns and travels 10 units of distance
 * His second turn is upward for 20 units
 * Third turn is to the left for 30 units
 * Fourth turn is the downward for 40 units
 * Fifth turn is to the right(again) for 50 units
 * … And thus he travels, every time increasing the travel 
 * distance by 10 units.
 * EG:
 * step1: 10, 0
 * step2: 10, 20
 * step3: -20, 20
 * step4: -20, -20
 * step5: 30, -20
 * step6: 90, -20
 * step7: 90, 70
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x, y;
    x = y = 0;
    for (int i = 0, factor = 10; i < n; i += 2) {
        x += factor;
        if (i % 4 == 0 && i != 0) {
            factor += 10;
            i -= 1; 
        }
        else {
            if (factor < 0)
                factor -= 20;
            else
                factor += 20;
            factor *= -1;
        }
    }
    for (int i = 1, factor = 20; i < n; i += 2) {
        if (i % 5 == 0) {
            factor += 10;
            i -= 1;
        }
        else {
            y += factor;
            if (factor < 0)
                factor -= 20;
            else
                factor += 20;
            factor *= -1;
        }
    }
    cout << x << " "<< y << endl;
}
