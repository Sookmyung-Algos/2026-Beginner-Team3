#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x, y;
    cin >> N;
    cin >> x >> y;

    vector<vector<int>> height(N, vector<int>(N));
    vector<vector<int>> dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
        }
    }

    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 ||
                j == 0 || j == N - 1) {

                int cost = height[i][j] * height[i][j];

                dist[i][j] = cost;
                pq.push({ cost, i, j });
            }
        }
    }

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    while (!pq.empty()) {
        auto [cost, r, c] = pq.top();
        pq.pop();

        if (cost > dist[r][c]) continue;

        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr < 0 || nr >= N ||
                nc < 0 || nc >= N) continue;

            int diff = height[nr][nc] - height[r][c];
            int moveCost;

            if (diff > 0)
                moveCost = diff * diff;
            else
                moveCost = -diff;

            int nextCost = cost + moveCost;

            if (nextCost < dist[nr][nc]) {
                dist[nr][nc] = nextCost;
                pq.push({ nextCost, nr, nc });
            }
        }
    }

    cout << dist[x - 1][y - 1] << '\n';

    return 0;
}