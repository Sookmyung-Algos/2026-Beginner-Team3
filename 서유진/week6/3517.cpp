#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    int m;
    cin >> m;

    vector<int> wanted(m);
    for (int i=0; i<m; i++) {
        cin >> wanted[i];
    }

    for (auto it = wanted.begin(); it != wanted.end(); it++) {
        if (binary_search(vec.begin(), vec.end(), *it) == true) {
            cout << lower_bound(vec.begin(), vec.end(), *it)- vec.begin() << ' ';
        }
        else {
            cout << -1 << ' ';
        }
    }
}