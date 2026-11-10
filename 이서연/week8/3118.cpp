#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    vector<long long> dist(N + 1, INF);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        long long cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now]) continue;

        for (auto next : graph[now]) {
            int nextNode = next.first;
            long long nextCost = cost + next.second;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }

    cout << dist[N] << '\n';

    return 0;
}