#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,k;
    int count=0;
    int a=0;
    
    cin >> n >> k;
    vector <int> v(n+1, 1);
    v[0] = 0;
    v[1] = 0;

    for (int i=2; i<=n+1; i++) {
        if (count == k) break;
        if (v[i] == 1) {
            v[i] == 0;
            count += 1;
            if (count == k) {
                a=i;
                break;
            }

            int j=2;
            while (i*j < n+1) {
                if (v[i*j] == 1) {
                    v[i*j] = 0;
                    count += 1;
                    if (count == k) {
                        a=i*j;
                        break;
                    }
                }
                j += 1;                
            }
        }
    }
    cout << a;
}