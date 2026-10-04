#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int via, int to) {
    if (n == 1) {
        cout << n << " : " << from << " -> " << to << '\n';
        return;
    }

    hanoi(n - 1, from, to, via);

    cout << n << " : " << from << " -> " << to << '\n';

    hanoi(n - 1, via, from, to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    hanoi(N, 1, 2, 3);

    return 0;
}