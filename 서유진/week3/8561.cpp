#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n=0;
    string name;
    map<string,int> m;
    while (true) {
        n++;
        cin >> name;
        if (name=="end") break;
        m[name]=n;
    }
    cout << m.size() << "\n";
    for (auto x: m) {
        cout << x.first << " " << x.second << "\n"; 
    }
}