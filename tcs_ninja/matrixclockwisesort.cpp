#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findmingreaterthan(vector<vector<int>> arr, int n, int mn) {
    int x = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > mn && arr[i][j] < x) {
                x = arr[i][j];
            }
        }
    }
    return x;
}

int main() 
{
    int n;
    cin >> n;
    int i, j, k = 0;
    vector<vector<int>> arr(n, vector<int> (n, 0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
		cin >> arr[i][j];
        }
	cout << endl;
    }
    int mn = INT_MIN;
    int x = n*n;
    i = j = k = 0;
    vector<vector<int>> res(n, vector<int> (n, 0));
    while (x--) {
        res[i][j] = findmingreaterthan(arr, n, mn);
        mn = res[i][j];
        if ((i == (n-k-1)) && (j == k)) {
            k++;
	}

        if ((i == k) && (j < (n-k-1))) {
            j++;
	}
        else if ((i < (n-k-1)) && (j == (n-k-1))) {
            i++;
	}
        else if ((i == (n-k-1)) && (j > k)) {
            j--;
	}
        else if ((i > k) && (j == k-1)) {
            i--;
	}
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
