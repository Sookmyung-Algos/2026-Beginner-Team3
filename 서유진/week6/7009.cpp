#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    vector<int> sus(q);
    for (int i=0; i<q; i++) {
        cin >> sus[i];
    }

    bool exist = false;

    for (auto it = sus.begin(); it != sus.end(); it++) {
        int x = *it;
        if (binary_search(vec.begin(), vec.end(), x) == false) {
            cout << x << ' ';
            exist = true;
        }
    }
    
    if (exist == false) {
        cout << -1;
    }
}