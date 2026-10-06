#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> paper;

void cut(int x, int y, int size) {
    int color = paper[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color) {
                same = false;
                break;
            }
        }
        if (!same)
            break;
    }

    if (same) {
        cout << color;
        return;
    }

    cout << 'X';
    int half = size / 2;

    cut(x, y, half);
    cut(x, y + half, half);
    cut(x + half, y, half);
    cut(x + half, y + half, half);
}

int main() {
    int N;
    cin >> N;

    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    cut(0, 0, N);

    return 0;
}