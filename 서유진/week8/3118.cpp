#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1);

    int a, b, c;

    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    const long long INF = 1e18;
    vector<long long> dajik(n+1, INF);

    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    dajik[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long weight = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (weight > dajik[now]) {
            continue;
        }

        for (int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].second;
            int cost = graph[now][i].first;

            if (dajik[next] > weight + cost) {
                dajik[next] = weight + cost;
                pq.push({dajik[next], next});
            }
        }
    }

    cout << dajik[n] << "\n";

    return 0;
}