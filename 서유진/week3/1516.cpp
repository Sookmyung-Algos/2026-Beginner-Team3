#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        string line,word;
        map <string,int> m;

        getline(cin,line);
        if (line=="END") break;

        stringstream ss(line);
        while (ss >> word) {
            if (!m.count(word)) {
                m[word]=1;
            }
            else {
                m[word]+=1;
            }
        }
        for (auto x: m) {
            cout << x.first << " : " << x.second << "\n";
        }
        m.clear();
    }
    
}