#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;
    int count=0;
    
    cin >> n >> m;
    vector <int> v(m+1, 1);
    v[0]=0;
    v[1]=0;

    for (int i=2; i<=m; i++) {
        if (v[i] == 1) {
            int j=2;
            while (i*j < m+1) {
                if (v[i*j] == 1) {
                    v[i*j] = 0;
                }
                j += 1;
            }           
        }
    }

    for (int i=n; i<=m; i++){
        if (v[i] == 1) {
            count += 1;
        }
    }
    cout << count;
}