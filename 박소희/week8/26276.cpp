#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));   // 양방향
        adj[b].push_back(make_pair(a, w));
    }

    int S, E;
    cin >> S >> E;

    vector<int> best(N + 1, 0);   // 0 = 아직 도달 못 함 (W >= 1)
    priority_queue<pair<int, int>> pq;   // (best 값, 정점), 큰 값 먼저

    best[S] = 1000000001;   // 시작점은 제한 없음
    pq.push(make_pair(best[S], S));

    while (!pq.empty()) {
        int b = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (b < best[u]) continue;
        if (u == E) break;

        for (int k = 0; k < adj[u].size(); k++) {
            int v = adj[u][k].first;
            int w = adj[u][k].second;
            int nb = (b < w) ? b : w;   // min(b, w)
            if (nb > best[v]) {
                best[v] = nb;
                pq.push(make_pair(nb, v));
            }
        }
    }

    cout << best[E] << endl;
    return 0;
}