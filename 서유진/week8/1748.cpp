#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int num, who, weight;
    const int INF = 1e9;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }
        else {
            vector<priority_queue<pair<int, int>, vector<pair<int, int>>,
                     greater<pair<int, int>>>> people(n+1);

            int a, b;

            for (int i=1; i<=n; i++) {
                cin >> num;
                for (int j=0; j<num; j++) {
                    cin >> a >> b;
                    people[i].push({b,a});
                }
            }

            vector<vector<pair<int, int>>> graph(n+1);

            for (int i=1; i<=n; i++) {
                while (!people[i].empty()) {
                    graph[i].push_back(people[i].top());
                    people[i].pop();
                }
            }

            int answer = INF;
            int who = 0;

            for (int i=1; i<=n; i++) {
                vector<int> dajik(n+1, INF);

                priority_queue<pair<int, int>, vector<pair<int, int>>,
                               greater<pair<int, int>>> pq;

                dajik[i] = 0;
                pq.push({0, i});

                while (!pq.empty()) {
                    int time = pq.top().first;
                    int now = pq.top().second;
                    pq.pop();

                    if (time > dajik[now]) {
                        continue;
                    }

                    for (int j=0; j<graph[now].size(); j++) {
                        int next = graph[now][j].second;
                        int cost = graph[now][j].first;

                        if (dajik[next] > time + cost) {
                            dajik[next] = time + cost;
                            pq.push({dajik[next], next});
                        }
                    }
                }

                int maxTime = 0;

                for (int j=1; j<=n; j++) {
                    maxTime = max(maxTime, dajik[j]);
                }

                if (maxTime < answer) {
                    answer = maxTime;
                    who = i;
                }
            }

            if (answer == INF) {
                cout << "disjoint\n";
            }
            else {
                cout << who << " " << answer << "\n";
            }
        }
    }

    return 0;
}