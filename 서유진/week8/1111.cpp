#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n;
    cin >> x >> y;

    vector<vector<int>> mount(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mount[i][j];
        }
    }

    const int INF = 1e9;
    vector<vector<int>> dajik(n, vector<int>(n, INF));

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==0 || i==n-1 || j==0 || j==n-1) {
                if (mount[i][j] == 0) {
                    dajik[i][j] = 0;
                    pq.push({0, {i, j}});
                }
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int weight = pq.top().first;
        int nowx = pq.top().second.first;
        int nowy = pq.top().second.second;
        pq.pop();

        if (weight > dajik[nowx][nowy]) {
            continue;
        }

        for (int i=0; i<4; i++) {
            int nextx = nowx + dx[i];
            int nexty = nowy + dy[i];

            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
                continue;
            }

            int diff = mount[nextx][nexty] - mount[nowx][nowy];
            int cost = 0;

            if (diff > 0) {
                cost = diff * diff;
            }
            else {
                cost = -diff;
            }

            if (dajik[nextx][nexty] > weight + cost) {
                dajik[nextx][nexty] = weight + cost;
                pq.push({dajik[nextx][nexty], {nextx, nexty}});
            }
        }
    }

    cout << dajik[x-1][y-1] << "\n";

    return 0;
}