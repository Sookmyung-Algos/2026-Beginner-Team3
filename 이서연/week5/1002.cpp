#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    int n[N];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    int G = n[0];
    int L = n[0];

    for (int i = 1; i < N; i++) {
        G = gcd(G, n[i]);
        L = lcm(L, n[i]);
    }

    cout << G << " " << L;
    return 0;
}