#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

int N;
int height[105][105];   // 0행, N+1행, 0열, N+1열은 바깥(높이 0)
int dist[105][105];

int cost(int h1, int h2) {
    if (h1 == h2) return 0;
    if (h1 > h2) return h1 - h2;            // 내리막
    return (h2 - h1) * (h2 - h1);           // 오르막
}

int main() {
    int ti, tj;
    cin >> N;
    cin >> ti >> tj;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> height[i][j];

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N + 1; j++)
            dist[i][j] = INF;

    // (-거리, 칸 번호)  칸 번호 = r * (N + 2) + c
    priority_queue<pair<int, int>> pq;

    // 바깥 테두리 칸 전부 시작점
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
                dist[i][j] = 0;
                pq.push(make_pair(0, i * (N + 2) + j));
            }
        }
    }

    while (!pq.empty()) {
        int d = -pq.top().first;
        int r = pq.top().second / (N + 2);
        int c = pq.top().second % (N + 2);
        pq.pop();

        if (d > dist[r][c]) continue;
        if (r == ti && c == tj) break;   // 정상 도착

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr > N + 1 || nc < 0 || nc > N + 1) continue;

            int nd = d + cost(height[r][c], height[nr][nc]);
            if (dist[nr][nc] > nd) {
                dist[nr][nc] = nd;
                pq.push(make_pair(-nd, nr * (N + 2) + nc));
            }
        }
    }

    cout << dist[ti][tj] << endl;
    return 0;
}