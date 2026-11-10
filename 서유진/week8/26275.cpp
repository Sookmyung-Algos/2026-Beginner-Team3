#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, w;
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> vec(m);

    for (int i = 0; i < m; i++) {
        cin >> vec[i].a >> vec[i].b >> vec[i].w;
    }

    int s, e;
    cin >> s >> e;

    sort(vec.begin(), vec.end(), [](Edge a, Edge b) {
        return a.w > b.w;
    });

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (auto edge : vec) {
        unite(edge.a, edge.b);

        if (find(s) == find(e)) {
            cout << edge.w;
            return 0;
        }
    }
}