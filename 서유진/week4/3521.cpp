#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    stack <int> s;
    int n=0;
    int a,weight,b=0;
    int num=0;

    for (int i=0; i<5; i++) {
        cin >> n;
        s.push(n);
    }

    cin >> n;

    for (int i=4; i>=0; i--) {
        a=s.top();
        s.pop();
        if (a) {
            weight=pow(2,i);
            b=n/weight;
            if (b) {
                if (b>=a) {
                    num+=a;
                    n-=a*weight;
                }
                else {
                    num+=b;
                    n-=b*weight;
                }
            }
        }
        if (!n) break;
    }

    if (!n) cout << num;
    else cout << "impossible";

}