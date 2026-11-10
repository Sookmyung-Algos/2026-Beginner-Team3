#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> graph[20001];

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    vector<int> dist(N + 1, INF);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now]) continue;

        for (auto next : graph[now]) {
            int nextNode = next.first;
            int nextCost = cost + next.second;

            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }

    cout << dist[N] << '\n';

    return 0;
}