// 디미고

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> h(n + 1);
    for (int j = 1; j <= n; j++) h[j] = j;

    int ans = 0; // k = 0이면 min(0, n) - 0 = 0
    for (int i = 1; i <= n; i++) {
        int v = 0;
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1] || h[j] < v) {
                int t = h[j]; h[j] = v; v = t; // 교차 또는 교환
            }
        }
        // LCS(s[1..i], s[i+1..n]) = j가 i+1..n인 범위에서 h[j] < i+1인 개수
        int l = i + 1, lcs = 0;
        for (int j = l; j <= n; j++)
            if (h[j] < l) lcs++;
        ans = max(ans, min(i, n - i) - lcs);
    }
    cout << ans << '\n';
}