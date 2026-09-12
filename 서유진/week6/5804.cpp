#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int left = 1;
    int right = x[n - 1] - x[0];
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        int cnt = 1;
        int last = x[0];

        for (int i = 1; i < n; i++) {
            if (x[i] - last >= mid) {
                cnt++;
                last = x[i];
            }
        }

        if (cnt >= k) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer;
}