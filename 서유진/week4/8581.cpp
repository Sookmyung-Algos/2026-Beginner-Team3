#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    int n=0;
    int m=0;
    long long sum=0;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> m;
        pq1.push(m);
    }

    for (int i=0; i<n; i++) {
        cin >> m;
        pq2.push(m);
    }

    for (int i=0; i<n; i++) {
        sum+=1LL*pq1.top()*pq2.top();
        pq1.pop();
        pq2.pop();
    }
    cout << sum;
}