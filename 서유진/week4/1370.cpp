#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int num, start, end;
    bool operator< (const Meeting& other)const {
        return end > other.end;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    Meeting m;
    priority_queue <Meeting> pq;
    vector <int> v;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m.num >> m.start >> m.end;
        pq.push(m);
    }
    
    int prev_m=0;

    for (int i=0; i<n; i++) {
        if (prev_m <= pq.top().start) {
            v.push_back(pq.top().num);
            prev_m = pq.top().end;
        }
        pq.pop();
    }

    cout << v.size() <<"\n";
    for (int num : v) {
        std::cout << num << " ";
    }
    return 0;
}