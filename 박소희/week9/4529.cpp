// 최장 증가 부분 수열
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> a(n), dp(n, 1);
//     for (auto& x : a) cin >> x;

//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++)
//             if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
//         ans = max(ans, dp[i]);
//     }
//     cout << ans << '\n';
// } DP 사용 시 시간초과

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> d; // d[k] = 길이 k+1인 증가 수열의 마지막 값 중 최솟값
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(d.begin(), d.end(), x); // x 이상인 첫 위치
        if (it == d.end()) d.push_back(x); // x가 가장 크면 길이를 1 늘림
        else *it = x;                      // 아니면 그 자리를 더 작은 값으로 교체
    }
    cout << d.size() << '\n';
}