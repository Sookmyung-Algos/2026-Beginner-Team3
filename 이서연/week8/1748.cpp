#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int dist[101][101];

int main() {
    int n;

    while (cin >> n && n != 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (int i = 1; i <= n; i++) {
            int m;
            cin >> m;

            for (int j = 0; j < m; j++) {
                int v, t;
                cin >> v >> t;
                dist[i][v] = min(dist[i][v], t);
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] == INF ||
                        dist[k][j] == INF) continue;

                    dist[i][j] = min(dist[i][j],
                        dist[i][k] + dist[k][j]);
                }
            }
        }

        int person = -1;
        int answer = INF;

        for (int i = 1; i <= n; i++) {
            int maxTime = 0;

            for (int j = 1; j <= n; j++) {
                maxTime = max(maxTime, dist[i][j]);
            }

            if (maxTime < answer) {
                answer = maxTime;
                person = i;
            }
        }

        if (person == -1)
            cout << "disjoint\n";
        else
            cout << person << " " << answer << "\n";
    }

    return 0;
}
