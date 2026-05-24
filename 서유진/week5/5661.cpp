#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,p,e;
    long long total=1;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> p >> e;
        total *= e+1;
    }
    cout << total;
}