#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

void floydWarshall (vector<int> T[], int n, vector<vector<int>> dist) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < T[i].size(); j++)
            dist[i][T[i][j]] = 1;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

void printall(vector<vector<int>> dist) {
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}
 
int main() {
    int n, q;
    cin >> n;
    cin >> q;
    vector<int> *T = new vector<int>[n];
    int x = n - 1;
    while (x-- != 0) {
        int u, v;
        cin >> u;
        cin >> v;
        T[u - 1].push_back(v - 1);
        T[v - 1].push_back(u - 1);
    }
    vector<vector<int>> dist(n, vector<int>(n));
    floydWarshall(T, n, dist);
    //printall(dist);
    while (q-- != 0) {
        int k;
        cin >> k;
        vector<int> set(k);
        for (int j = 0; j < k; j++) {
            cin >> set[j];
        }
        int s = 0;
        for (x = 0; x < k - 1; x++) {
            for (int y = x + 1; y < k; y++) {
                s += set[x] * set[y] * dist[x - 1][y - 1];
            }
        }
        s = s % int((pow(10, 9) + 7));
        cout << s << endl;
    }
    return 0;
}
