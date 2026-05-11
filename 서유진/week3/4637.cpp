#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;
    char c;
    set <int> s{};
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c >> m;
        if (c=='i') {
            s.insert(m);
        }
        else if (c=='r') {
            if (s.count(m)) s.erase(m);
        }
    }

    for (auto x: s) cout << x << " ";
}