#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int blue=0;
int white=0;

bool color(int x, int y, int s, vector<vector<int>>& vec) {
    for (int i=x; i<=x+s-1; i++) {
        for (int j=y; j<=y+s-1; j++) {
            if (vec[x][y] != vec[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void cut(int x, int y, int s, vector<vector<int>>& vec) {
    if (!color(x, y, s, vec)) {
        s /= 2;
        cut(x, y, s, vec);
        cut(x+s, y, s, vec);
        cut(x, y+s, s, vec);
        cut(x+s, y+s, s, vec);
    }
    else {
        if (vec[x][y] == 1) {
            blue++;
        }
        else {
            white++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n=0;
    cin >> n;

    vector<vector<int>> vec(n+1, vector<int>(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> vec[i][j];
        }
    }
    
    cut(1, 1, n, vec);

    cout << white << '\n';
    cout << blue << '\n';
}