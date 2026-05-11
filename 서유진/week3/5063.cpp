#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string line1,line2,word;
    set<string> s {};
    set<string> dup{};

    getline(cin,line1);
    stringstream ss1(line1);
    while (ss1 >> word) {
        s.insert(word);
    }

    getline(cin,line2);
    stringstream ss2(line2);
    while (ss2 >> word) {
        if (s.count(word)) dup.insert(word);
    }
    
    for (auto x: dup) {
        cout << x << " ";
    }
}