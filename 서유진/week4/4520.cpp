#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (s[j] == 'H') {
                    s[j] = 'X';
                    count++;
                    break;
                }
            }
        }
    }

    cout << count;
}