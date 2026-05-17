#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    long long ans = 0;
    long long minCost = 1e18; // 지금까지의 최소 구매단가(초기값 충분히 크게)

    for (int i = 0; i < N; i++) {
        long long C, Y;
        cin >> C >> Y;

        // 이전 주 최소단가에 보관비 1주 추가, 이번 주 단가 중 min
        minCost = min(minCost + S, C);
        ans += minCost * Y;
    }

    cout << ans;

    return 0;
}