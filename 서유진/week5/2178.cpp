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

    int R1 = v[0];
    int R,A,B;
    
    for (int i=1; i<n; i++) {
        R = v[i];
        A = R1/gcd(R1, R);
        B = R/gcd(R1,R);
        cout << A << "/" << B << "\n";
    }

}