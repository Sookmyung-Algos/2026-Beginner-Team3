#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        // adj[i] : i가 정보를 전달하는 (상대 번호, 시간) 목록
        vector<vector<pair<int, int>>> adj(N + 1);
        for (int i = 1; i <= N; i++) {
            int n;
            cin >> n;
            for (int k = 0; k < n; k++) {
                int j, t;
                cin >> j >> t;
                adj[i].push_back(make_pair(j, t));
            }
        }

        int bestNode = -1;
        int bestTime = INF;

        for (int s = 1; s <= N; s++) {
            vector<int> dist(N + 1, INF);
            priority_queue<pair<int, int>> pq;   // (-거리, 정점)

            dist[s] = 0;
            pq.push(make_pair(0, s));

            while (!pq.empty()) {
                int d = -pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (d > dist[u]) continue;

                for (int k = 0; k < adj[u].size(); k++) {
                    int v = adj[u][k].first;
                    int w = adj[u][k].second;
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.push(make_pair(-dist[v], v));
                    }
                }
            }

            // 가장 늦게 정보를 받는 사람의 시간
            int mx = 0;
            for (int i = 1; i <= N; i++) {
                if (dist[i] > mx) mx = dist[i];
            }

            if (mx < bestTime) {
                bestTime = mx;
                bestNode = s;
            }
        }

        if (bestTime == INF) cout << "disjoint" << endl;
        else cout << bestNode << " " << bestTime << endl;
    }
    return 0;
}