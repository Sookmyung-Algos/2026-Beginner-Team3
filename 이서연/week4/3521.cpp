#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, e, N;
    cin >> a >> b >> c >> d >> e >> N;

    int weight[5] = { 16, 8, 4, 2, 1 };
    int cnt[5] = { e, d, c, b, a };

    int answer = 0;

    for (int i = 0; i < 5; i++) {
        int use = min(cnt[i], N / weight[i]);
        N -= use * weight[i];
        answer += use;
    }

    if (N == 0) {
        cout << answer;
    }
    else {
        cout << "impossible";
    }

    return 0;
}
