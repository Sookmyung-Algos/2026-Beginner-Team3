#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
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

    for (int i = 1; i < N; i++) {
        cout << n[0] / gcd(n[0], n[i]) << "/" << n[i] / gcd(n[0], n[i]) << "\n";
    }
    return 0;
}