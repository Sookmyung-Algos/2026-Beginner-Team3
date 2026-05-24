#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int g = v[0];
    int l = v[0];

    for (int i = 1; i < n; i++) {
        g = gcd(g, v[i]);
        l = l / gcd(l, v[i]) * v[i];
    }

    cout << g << " " << l;
}