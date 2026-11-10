#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int A, B, W;
        cin >> A >> B >> W;

        graph[A].push_back({ B, W });
        graph[B].push_back({ A, W });
    }

    int S, E;
    cin >> S >> E;

    vector<int> trust(N + 1, 0);

    priority_queue<pair<int, int>> pq;

    trust[S] = 1000000000;
    pq.push({ trust[S], S });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost < trust[now]) continue;

        if (now == E) {
            cout << cost << '\n';
            return 0;
        }

        for (auto next : graph[now]) {
            int nextNode = next.first;
            int weight = next.second;

            int nextTrust = min(cost, weight);

            if (nextTrust > trust[nextNode]) {
                trust[nextNode] = nextTrust;
                pq.push({ nextTrust, nextNode });
            }
        }
    }

    cout << trust[E] << '\n';

    return 0;
}