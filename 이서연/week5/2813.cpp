#include <iostream>

using namespace std;

int eratosthenes(int m, int n) {
    int a[10000001];

    for (int i = 2; i <= n; i++) {
        a[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) continue;

        for (int j = i + i; j <= n; j += i) {
            a[j] = 0;
        }
    }


    int count = 0;
    for (int i = m + 1; i <= n; i++) {
        if (a[i] != 0) count += 1;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    cout << eratosthenes(M, N);
    return 0;
}