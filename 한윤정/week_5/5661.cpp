#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long total_divisors = 1;

    for (int i = 0; i < n; i++) {
        int p, e;
        cin >> p >> e;
        total_divisors *= (e + 1);
    }

    cout << total_divisors << "\n";

    return 0;
}