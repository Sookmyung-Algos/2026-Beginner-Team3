// 전깃줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> w(n);
    for (auto& p : w) cin >> p.first >> p.second;

    sort(w.begin(), w.end()); // A 위치 기준 정렬

    vector<int> dp(n, 1);
    int lis = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (w[j].second < w[i].second) dp[i] = max(dp[i], dp[j] + 1);
        lis = max(lis, dp[i]);
    }
    cout << n - lis << '\n';
}