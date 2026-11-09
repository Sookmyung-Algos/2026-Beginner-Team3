#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1000000000000000000LL;   // 10^18

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));   // a -> b 단방향
    }

    vector<long long> dist(N + 1, INF);
    priority_queue<pair<long long, int>> pq;   // (-거리, 정점)

    dist[1] = 0;
    pq.push(make_pair(0LL, 1));

    while (!pq.empty()) {
        long long d = -pq.top().first;
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

    cout << dist[N] << endl;
    return 0;
}