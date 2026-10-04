#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>>& a, int x, int y, int n) {
    int first = a[x][y];
    bool same = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (a[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        cout << first;
        return;
    }

    cout << "X";

    int half = n / 2;

    solve(a, x, y, half);
    solve(a, x, y + half, half);
    solve(a, x + half, y, half);
    solve(a, x + half, y + half, half);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    solve(a, 0, 0, N);

    return 0;
}