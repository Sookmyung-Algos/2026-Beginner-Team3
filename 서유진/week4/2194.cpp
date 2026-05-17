#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    long long cost = 0;
    int best = 5000;

    for (int i = 0; i < n; i++) {
        int c, y;
        cin >> c >> y;

        best = min(c, best + s);
        cost += 1LL * best * y;
    }

    cout << cost;
}