#include <iostream>

using namespace std;

void eratosthenes(int n, int k) {
    int a[1001];

    for (int i = 2; i <= n; i++) {
        a[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) continue;

        for (int j = i; j <= n; j += i) {

            if (a[j] != 0) {
                k--;

                if (k == 0) {
                    cout << a[j];
                    return;
                }

                a[j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    eratosthenes(N, K);

    return 0;
}